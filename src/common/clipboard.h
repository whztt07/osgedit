#ifndef __CLIPBOARD_H__
#define __CLIPBOARD_H__

#include <reflection/classreflection.h>
#include <osg/ref_ptr>
#include "export.h"

/**
 * OSGEdit clipboard, storing objects for copy/paste
 */
class COMMON_EXPORT Clipboard {
public:
    /// Get the contents of the clipboard
	static ClassReflection *get() { return _contents.get(); }

    /// Set the contents of the clipboard
    static void set(ClassReflection *node) { _contents=node; }

private:
    /// The last object copied
	static osg::ref_ptr<ClassReflection> _contents;
};

#endif

