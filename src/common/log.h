#ifndef __LOG_H__
#define __LOG_H__

#include <osg/Referenced>
#include <osg/ref_ptr>
#include <vector>
#include <string>
#include "export.h"

/**
 * OSGEdit logging system. Allows logging to different targets.
 */
class COMMON_EXPORT Log {
public:
	/**
	 * Level of log messages
     */
	typedef enum { INFO, WARNING, ERROR } Level;

	/**
	 * Log implementation
     */
	class Impl: public osg::Referenced {
	public:
		typedef std::vector< osg::ref_ptr<Impl> > Vector;
		virtual void log(const std::string &msg, Log::Level level) = 0;
	};

    /// singleton
	static Log *instance();

	/**
	 * Adds a new log implementation to the logging system
     */
	inline void addImpl(Impl *impl) {
        _logImpls.push_back(impl);
	}

	/**
	 * Add an entry to the log system
     */
	void log(const std::string &msg, Level level);
private:
	Log(){}
	Impl::Vector _logImpls;
};

#define LOG(msg, level) Log::instance()->log(msg, level)

#endif//__LOG_H__
