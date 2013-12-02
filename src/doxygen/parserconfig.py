##########################
## Sometimes doxygen doesn't detect the class hierarchy :(
##########################
hardWiredParents = {
    'osg::DrawArrays': 'osg::PrimitiveSet',
    'osg::DrawArrayLengths': 'osg::PrimitiveSet',
    'osg::DrawElementsUByte': 'osg::PrimitiveSet',
    'osg::DrawElementsUShort': 'osg::PrimitiveSet',
    'osg::DrawElementsUInt': 'osg::PrimitiveSet',
    'osgParticle::RandomRateCounter': 'osgParticle::VariableRateCounter',
    'osgParticle::VariableRateCounter': 'osgParticle::Counter'
}

##########################
# Key: Name of the variable made up from the getter/setter name
# Value: List of possible variable values to bind the getter/setter to
##########################
aliases = {
    '_boundingBox': ['_bbox'],
    '_child': ['_children'],
    '_renderBinMode': ['_binMode'],
    '_binNumber': ['_binNum'],
    '_primitiveSet': ['_primitives'],
    '_primitiveSets': ['_primitives'],
    '_attributeList': ['_attribute'],
    '_drawables': ['_drawable'],
    '_sourceRGB': ['_source_factor'],
    '_sourceAlpha': ['_source_factor_alpha'],
    '_destinationRGB': ['_destination_factor'],
    '_destinationAlpha': ['_destination_factor_alpha'],
    '_initialSpeedRange': ['_speed_range'],
    '_initialRotationalSpeedRange': ['_rot_speed_range'],
    '_center': ['center_'],
    '_shader': ['_shaderList'],
    '_shaders': ['_shaderList']
}

############################
# OpenGL fake enumerations
############################
glEnums = {
        'osg::BlendFunc::_source_factor': [
            'GL_ZERO',
            'GL_ONE',
            'GL_DST_COLOR',
            'GL_ONE_MINUS_DST_COLOR',
            'GL_SRC_ALPHA',
            'GL_ONE_MINUS_SRC_ALPHA',
            'GL_DST_ALPHA',
            'GL_ONE_MINUS_DST_ALPHA',
            'GL_SRC_ALPHA_SATURATE'
        ],
        'osg::BlendFunc::_source_factor_alpha': [
            'GL_ZERO',
            'GL_ONE',
            'GL_DST_COLOR',
            'GL_ONE_MINUS_DST_COLOR',
            'GL_SRC_ALPHA',
            'GL_ONE_MINUS_SRC_ALPHA',
            'GL_DST_ALPHA',
            'GL_ONE_MINUS_DST_ALPHA',
            'GL_SRC_ALPHA_SATURATE'
        ],
        'osg::BlendFunc::_destination_factor': [
            'GL_ZERO',
            'GL_ONE',
            'GL_SRC_COLOR',
            'GL_ONE_MINUS_SRC_COLOR',
            'GL_DST_COLOR',
            'GL_ONE_MINUS_DST_COLOR',
            'GL_SRC_ALPHA',
            'GL_ONE_MINUS_SRC_ALPHA',
            'GL_DST_ALPHA',
            'GL_ONE_MINUS_DST_ALPHA',
            'GL_CONSTANT_COLOR',
            'GL_ONE_MINUS_CONSTANT_COLOR',
            'GL_CONSTANT_ALPHA',
            'GL_ONE_MINUS_CONSTANT_ALPHA'
        ],
        'osg::BlendFunc::_destination_factor_alpha': [
            'GL_ZERO',
            'GL_ONE',
            'GL_SRC_COLOR',
            'GL_ONE_MINUS_SRC_COLOR',
            'GL_DST_COLOR',
            'GL_ONE_MINUS_DST_COLOR',
            'GL_SRC_ALPHA',
            'GL_ONE_MINUS_SRC_ALPHA',
            'GL_DST_ALPHA',
            'GL_ONE_MINUS_DST_ALPHA',
            'GL_CONSTANT_COLOR',
            'GL_ONE_MINUS_CONSTANT_COLOR',
            'GL_CONSTANT_ALPHA',
            'GL_ONE_MINUS_CONSTANT_ALPHA'
        ],
        'osg::Image::_pixelFormat': [
            'GL_COLOR_INDEX',
            'GL_RED',
            'GL_GREEN',
            'GL_BLUE',
            'GL_ALPHA',
            'GL_RGB',
            'GL_RGBA',
            'GL_LUMINANCE',
            'GL_LUMINANCE_ALPHA'
        ],
        'osg::Image::_dataType': [
            'GL_UNSIGNED_BYTE',
            'GL_BYTE',
            'GL_UNSIGNED_SHORT',
            'GL_SHORT',
            'GL_UNSIGNED_INT',
            'GL_INT',
            'GL_FLOAT',
            'GL_BITMAP'
        ],
        'osg::Texture::_sourceFormat': [
            'GL_COLOR_INDEX',
            'GL_RED',
            'GL_GREEN',
            'GL_BLUE',
            'GL_ALPHA',
            'GL_RGB',
            'GL_RGBA',
            'GL_LUMINANCE',
            'GL_LUMINANCE_ALPHA'
        ],
        'osg::Texture::_sourceType': [
            'GL_UNSIGNED_BYTE',
            'GL_BYTE',
            'GL_UNSIGNED_SHORT',
            'GL_SHORT',
            'GL_UNSIGNED_INT',
            'GL_INT',
            'GL_FLOAT',
            'GL_BITMAP'
        ]
}

############################
# Table values, not detected by the parser
############################
tableValues = {
    'osg::Switch': {
        '_values': {
            'columns': [
                ('Enabled', 'bool', 'getValue')
            ],
            'rows': 'children',
            'setter': 'setValue'
        }
    },
    'osg::Sequence': {
        '_frameTimes': {
            'columns': [
                ('Time', 'float', 'getTime')
            ],
            'rows': 'children',
            'setter': 'setTime'
        }
    },
    'osg::LOD': {
        '_ranges': {
            'columns': [
                ('Min', 'float', 'getMinRange'),
                ('Max', 'float', 'getMaxRange')
            ],
            'rows': 'children',
            'setter': 'setRange'
        }
    }
}


