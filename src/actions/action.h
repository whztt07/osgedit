#ifndef __ACTION_H__
#define __ACTION_H__
#include "export.h"
#include <osg/Referenced>

/**
 * OSGEdit action.
 */
class ACTION_EXPORT Action: public osg::Referenced {
public:
	virtual ~Action(){}

	/**
	 * Runs the action
     * @return true if it has been performed, false if not
     */
	virtual bool run() = 0;
};

#endif//__ACTION_H__
