#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>

#include <command/commandadd.h>
#include <command/metacommand.h>

template <class What>
class ActionAdd: public Action {
public:
	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("You have to select some node to add children into.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else {
			ClassReflection *child = osgedit::OSGEdit::reflect(new What);
			osgedit::OSGEdit::autoName(child);
			osg::ref_ptr<MetaCommand> metaCmd = new MetaCommand("Add "+child->getName()+" to selected");
			for (unsigned i = 0; i < selection->getNumItems(); i++) {
				osgedit::Selection::ObjectPath &path = selection->getItem(i);
                ClassReflection *parent = path.back().get();
				metaCmd->addSubCommand(new CommandAdd(parent, child));
			}
			try {
				metaCmd->execute();
                return true;
			} catch (std::exception &e) {
				Gtk::MessageDialog dialog("You can not add " + child->getType() + " inside the selection. Cancelling.", false, Gtk::MESSAGE_WARNING);
				dialog.run();
				try {
					metaCmd->undo();
				} catch (std::exception &e) {
					// IGNORE. We have just warned in the execute :)
				}
                return false;
			}
		}
	}
};

#include <osg/Geode>
#include <osg/Billboard>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osg/DrawPixels>

#include <osg/Shape>

#define SUPPORT_ADD(namespace, Class) \
	typedef ActionAdd<namespace::Class> ActionAdd##Class; \
	REGISTER_ACTION(ActionAdd##Class, "Add "#namespace"::"#Class)

//Each action is registered as ActionAddXXX where XXX is the class

/** Leaves **/
SUPPORT_ADD(osg, Geode);
SUPPORT_ADD(osg, Billboard);
SUPPORT_ADD(osg, DrawPixels);

/** Groups **/
#include <osg/Group>
#include <osg/ClearNode>
#include <osg/ClipNode>
#include <osg/CoordinateSystemNode>
#include <osg/LightSource>
#include <osg/LOD>
#include <osg/OccluderNode>
#include <osg/Projection>
#include <osg/ProxyNode>
#include <osg/Sequence>
#include <osg/Switch>
#include <osg/TexGenNode>
#include <osg/AutoTransform>
#include <osg/Camera>
#include <osg/CameraView>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>

SUPPORT_ADD(osg, Group);
SUPPORT_ADD(osg, ClearNode);
SUPPORT_ADD(osg, ClipNode);
SUPPORT_ADD(osg, CoordinateSystemNode);
SUPPORT_ADD(osg, LightSource);
SUPPORT_ADD(osg, LOD);
SUPPORT_ADD(osg, OccluderNode);
SUPPORT_ADD(osg, Projection);
SUPPORT_ADD(osg, ProxyNode);
SUPPORT_ADD(osg, Sequence);
SUPPORT_ADD(osg, Switch);
SUPPORT_ADD(osg, TexGenNode);
SUPPORT_ADD(osg, AutoTransform);
SUPPORT_ADD(osg, Camera);
SUPPORT_ADD(osg, CameraView);
SUPPORT_ADD(osg, MatrixTransform);
SUPPORT_ADD(osg, PositionAttitudeTransform);


/** Drawables **/
SUPPORT_ADD(osg, Geometry);
SUPPORT_ADD(osg, ShapeDrawable);

/** Shapes **/
SUPPORT_ADD(osg, Sphere);
SUPPORT_ADD(osg, Box);
SUPPORT_ADD(osg, Cone);
SUPPORT_ADD(osg, Cylinder);
SUPPORT_ADD(osg, Capsule);
SUPPORT_ADD(osg, TriangleMesh);
SUPPORT_ADD(osg, HeightField);
SUPPORT_ADD(osg, CompositeShape);

/** State attributes **/
#include <osg/AlphaFunc>
#include <osg/BlendColor>
#include <osg/BlendEquation>
#include <osg/BlendFunc>
#include <osg/ClampColor>
#include <osg/ClipPlane>
#include <osg/ColorMask>
#include <osg/ColorMatrix>
#include <osg/CullFace>
#include <osg/Depth>
#include <osg/Fog>
#include <osg/FragmentProgram>
#include <osg/FrameBufferObject>
#include <osg/FrontFace>
#include <osg/Light>
#include <osg/LightModel>
#include <osg/LineStipple>
#include <osg/LineWidth>
#include <osg/LogicOp>
#include <osg/Material>
#include <osg/Multisample>
#include <osg/Point>
#include <osg/PointSprite>
#include <osg/PolygonMode>
#include <osg/PolygonOffset>
#include <osg/PolygonStipple>
#include <osg/Program>
#include <osg/Scissor>
#include <osg/ShadeModel>
#include <osg/Stencil>
#include <osg/StencilTwoSided>
#include <osg/TexEnv>
#include <osg/TexEnvCombine>
#include <osg/TexEnvFilter>
#include <osg/TexGen>
#include <osg/TexMat>
#include <osg/Texture>
#include <osg/VertexProgram>
#include <osg/Viewport>
#include <osg/Texture1D>
#include <osg/Texture2D>
#include <osg/Texture2DArray>
#include <osg/Texture3D>
#include <osg/TextureCubeMap>
#include <osg/TextureRectangle>

SUPPORT_ADD(osg, StateSet);
SUPPORT_ADD(osg, AlphaFunc);
SUPPORT_ADD(osg, BlendColor);
SUPPORT_ADD(osg, BlendEquation);
SUPPORT_ADD(osg, BlendFunc);
SUPPORT_ADD(osg, ClampColor);
SUPPORT_ADD(osg, ClipPlane);
SUPPORT_ADD(osg, ColorMask);
SUPPORT_ADD(osg, ColorMatrix);
SUPPORT_ADD(osg, CullFace);
SUPPORT_ADD(osg, Depth);
SUPPORT_ADD(osg, Fog);
SUPPORT_ADD(osg, FragmentProgram);
SUPPORT_ADD(osg, FrameBufferObject);
SUPPORT_ADD(osg, FrontFace);
SUPPORT_ADD(osg, Light);
SUPPORT_ADD(osg, LightModel);
SUPPORT_ADD(osg, LineStipple);
SUPPORT_ADD(osg, LineWidth);
SUPPORT_ADD(osg, LogicOp);
SUPPORT_ADD(osg, Material);
SUPPORT_ADD(osg, Multisample);
SUPPORT_ADD(osg, Point);
SUPPORT_ADD(osg, PointSprite);
SUPPORT_ADD(osg, PolygonMode);
SUPPORT_ADD(osg, PolygonOffset);
SUPPORT_ADD(osg, PolygonStipple);
SUPPORT_ADD(osg, Program);
SUPPORT_ADD(osg, Scissor);
SUPPORT_ADD(osg, ShadeModel);
SUPPORT_ADD(osg, Stencil);
SUPPORT_ADD(osg, StencilTwoSided);
SUPPORT_ADD(osg, TexEnv);
SUPPORT_ADD(osg, TexEnvCombine);
SUPPORT_ADD(osg, TexEnvFilter);
SUPPORT_ADD(osg, TexGen);
SUPPORT_ADD(osg, TexMat);
SUPPORT_ADD(osg, Texture1D);
SUPPORT_ADD(osg, Texture2D);
SUPPORT_ADD(osg, Texture2DArray);
SUPPORT_ADD(osg, Texture3D);
SUPPORT_ADD(osg, TextureCubeMap);
SUPPORT_ADD(osg, TextureRectangle);
SUPPORT_ADD(osg, VertexProgram);
SUPPORT_ADD(osg, Viewport);

#include <osg/Shader>
SUPPORT_ADD(osg, Shader);

#include <osgText/Text>
SUPPORT_ADD(osgText, Text);
