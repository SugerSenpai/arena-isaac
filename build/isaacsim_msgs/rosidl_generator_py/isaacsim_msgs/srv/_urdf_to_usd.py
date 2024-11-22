# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaacsim_msgs:srv/UrdfToUsd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UrdfToUsd_Request(type):
    """Metaclass of message 'UrdfToUsd_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaacsim_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaacsim_msgs.srv.UrdfToUsd_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__urdf_to_usd__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__urdf_to_usd__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__urdf_to_usd__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__urdf_to_usd__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__urdf_to_usd__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UrdfToUsd_Request(metaclass=Metaclass_UrdfToUsd_Request):
    """Message class 'UrdfToUsd_Request'."""

    __slots__ = [
        '_using_arena_robot',
        '_urdf_path',
        '_robot_name',
        '_number_robot',
    ]

    _fields_and_field_types = {
        'using_arena_robot': 'boolean',
        'urdf_path': 'string',
        'robot_name': 'string',
        'number_robot': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.using_arena_robot = kwargs.get('using_arena_robot', bool())
        self.urdf_path = kwargs.get('urdf_path', str())
        self.robot_name = kwargs.get('robot_name', str())
        self.number_robot = kwargs.get('number_robot', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.using_arena_robot != other.using_arena_robot:
            return False
        if self.urdf_path != other.urdf_path:
            return False
        if self.robot_name != other.robot_name:
            return False
        if self.number_robot != other.number_robot:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def using_arena_robot(self):
        """Message field 'using_arena_robot'."""
        return self._using_arena_robot

    @using_arena_robot.setter
    def using_arena_robot(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'using_arena_robot' field must be of type 'bool'"
        self._using_arena_robot = value

    @builtins.property
    def urdf_path(self):
        """Message field 'urdf_path'."""
        return self._urdf_path

    @urdf_path.setter
    def urdf_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'urdf_path' field must be of type 'str'"
        self._urdf_path = value

    @builtins.property
    def robot_name(self):
        """Message field 'robot_name'."""
        return self._robot_name

    @robot_name.setter
    def robot_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_name' field must be of type 'str'"
        self._robot_name = value

    @builtins.property
    def number_robot(self):
        """Message field 'number_robot'."""
        return self._number_robot

    @number_robot.setter
    def number_robot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'number_robot' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'number_robot' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._number_robot = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_UrdfToUsd_Response(type):
    """Metaclass of message 'UrdfToUsd_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaacsim_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaacsim_msgs.srv.UrdfToUsd_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__urdf_to_usd__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__urdf_to_usd__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__urdf_to_usd__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__urdf_to_usd__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__urdf_to_usd__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UrdfToUsd_Response(metaclass=Metaclass_UrdfToUsd_Response):
    """Message class 'UrdfToUsd_Response'."""

    __slots__ = [
        '_usd_path',
        '_prim_path',
    ]

    _fields_and_field_types = {
        'usd_path': 'string',
        'prim_path': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.usd_path = kwargs.get('usd_path', str())
        self.prim_path = kwargs.get('prim_path', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.usd_path != other.usd_path:
            return False
        if self.prim_path != other.prim_path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def usd_path(self):
        """Message field 'usd_path'."""
        return self._usd_path

    @usd_path.setter
    def usd_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'usd_path' field must be of type 'str'"
        self._usd_path = value

    @builtins.property
    def prim_path(self):
        """Message field 'prim_path'."""
        return self._prim_path

    @prim_path.setter
    def prim_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'prim_path' field must be of type 'str'"
        self._prim_path = value


class Metaclass_UrdfToUsd(type):
    """Metaclass of service 'UrdfToUsd'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('isaacsim_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'isaacsim_msgs.srv.UrdfToUsd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__urdf_to_usd

            from isaacsim_msgs.srv import _urdf_to_usd
            if _urdf_to_usd.Metaclass_UrdfToUsd_Request._TYPE_SUPPORT is None:
                _urdf_to_usd.Metaclass_UrdfToUsd_Request.__import_type_support__()
            if _urdf_to_usd.Metaclass_UrdfToUsd_Response._TYPE_SUPPORT is None:
                _urdf_to_usd.Metaclass_UrdfToUsd_Response.__import_type_support__()


class UrdfToUsd(metaclass=Metaclass_UrdfToUsd):
    from isaacsim_msgs.srv._urdf_to_usd import UrdfToUsd_Request as Request
    from isaacsim_msgs.srv._urdf_to_usd import UrdfToUsd_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
