#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <memory>

/** Generic function, without args */
template <typename R, class Class>
class _Function {
public:
	virtual ~_Function(){}
	virtual R operator()(Class *obj) = 0;
};

/** Concrete function, without args */
template <typename R, class Class, typename Fun>
class _FunctionImpl: public _Function<R, Class> {
public:
	_FunctionImpl(Fun fun): _fun(fun) {}
	virtual R operator()(Class *obj) { return (obj->*_fun)(); }
private:
    Fun _fun;
};

/** Generic function, 1 arg */
template <typename R, class Class, typename Arg>
class _FunctionArg {
public:
	virtual ~_FunctionArg() {}
	virtual R operator()(Class *obj, Arg &arg) = 0;
};

/** Concrete function, 1 arg */
template <typename R, class Class, typename Arg, typename Fun>
class _FunctionImplArg: public _FunctionArg<R, Class, Arg> {
public:
	_FunctionImplArg(Fun fun): _fun(fun) {}
	virtual R operator()(Class *obj, Arg &arg) { return (obj->*_fun)(arg); }
private:
    Fun _fun;
};

/** VOID exception */
template <class Class, typename Arg, typename Fun>
class _FunctionImplArg<void, Class, Arg, Fun>: public _FunctionArg<void, Class, Arg> {
public:
	_FunctionImplArg(Fun fun): _fun(fun) {}
	virtual void operator()(Class *obj, Arg &arg) { (obj->*_fun)(arg); }
private:
    Fun _fun;
};

/** Function */
template<typename Return, class Class>
class Function {
public:
	template <typename Fun>
		Function(Fun function): _fun(new _FunctionImpl<Return, Class, Fun>(function)) {}
	inline Return operator()(Class *obj) {
		return (*_fun)(obj);
	}
private:
	std::auto_ptr< _Function<Return, Class> > _fun;
};


/** Function with 1 arg */
template<typename Return, class Class, typename Arg>
class FunctionArg {
public:
	template <typename Fun>
		FunctionArg(Fun function): _fun(new _FunctionImplArg<Return, Class, Arg, Fun>(function)) {}
	inline Return operator()(Class *obj, Arg &arg) {
		return (*_fun)(obj, arg);
	}
private:
	std::auto_ptr< _FunctionArg<Return, Class, Arg> > _fun;
};


/** VOID exception */
template<class Class, typename Arg>
class FunctionArg<void, Class, Arg> {
public:
	template <typename Fun>
		FunctionArg(Fun function): _fun(new _FunctionImplArg<void, Class, Arg, Fun>(function)) {}
	inline void operator()(Class *obj, Arg &arg) {
		(*_fun)(obj, arg);
	}
private:
	std::auto_ptr< _FunctionArg<void, Class, Arg> > _fun;
};

#endif//__FUNCTIONS_H__
