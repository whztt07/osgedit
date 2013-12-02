#ifndef __VISITOR_H__
#define __VISITOR_H__

/**
 * Acyclic visitor. Not as fast as the default cyclic one, but much more
 * generic and decoupled. It can even accept objects from different
 * hierarchies ;)
 *
 * Usage:
 *  a) Defining your visitor class:
 *    class MyVisitor: public BaseVisitor,
 *         public Visitor<SomeClass>,
 *         public Visitor<SomeOtherClass>,
 *         [...] {
 *      void apply(SomeClass *c);
 *      void apply(SomeOtherClass *c2);
 *
 *  b) Defining a visitable clase
 *    class SomeClass: public BaseVisitable {
 *      META_VISITABLE();
 *    }
 *
 *  c) If you don't want to return void?
 *    class MyVisitor: public BaseVisitor<int>,
 *         public Visitor<SomeClass>,
 *         public Visitor<SomeOtherClass>,
 *         [...] {
 *      int apply(SomeClass *c);
 *      int apply(SomeOtherClass *c2);
 *
 */


/**
 * Base visitor class
 */
class BaseVisitor {
public:
	virtual ~BaseVisitor(){}
};

/**
 * Templated visitor interface
 */
template <class T, typename Return = void>
class Visitor {
public:
	virtual ~Visitor(){}
	virtual Return apply(T*) = 0;
};

/**
 * Base class for any visitable thing
 */
template <typename R = void>
class BaseVisitable {
public:
    typedef R Return;
	virtual ~BaseVisitable() {}
    virtual Return accept(BaseVisitor &visitor) = 0;
protected:
    template<class T>
		inline static Return acceptHelper(T *visited, BaseVisitor &visitor) {
			Visitor<T, Return> *p = dynamic_cast<Visitor<T, Return>*>(&visitor);
			if (p != 0) {
                return p->apply(visited);
			}
		}
};

#define META_VISITABLE() \
	virtual Return accept(BaseVisitor &visitor) { return acceptHelper(this, visitor); }

#endif//__VISITOR_H__

