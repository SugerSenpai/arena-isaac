# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaacsim_msgs:srv/ImportUsd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

<<<<<<< HEAD
=======
import math  # noqa: E402, I100

# Member 'position'
# Member 'orientation'
import numpy  # noqa: E402, I100

>>>>>>> an
import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImportUsd_Request(type):
    """Metaclass of message 'ImportUsd_Request'."""

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
                'isaacsim_msgs.srv.ImportUsd_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__import_usd__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__import_usd__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__import_usd__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__import_usd__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__import_usd__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
<<<<<<< HEAD
        }

=======
            'POSITION__DEFAULT': numpy.array((0.0, 0.0, 0.0, ), dtype=numpy.float32),
            'ORIENTATION__DEFAULT': numpy.array((1.0, 0.0, 0.0, 0.0, ), dtype=numpy.float32),
        }

    @property
    def POSITION__DEFAULT(cls):
        """Return default value for message field 'position'."""
        return numpy.array((0.0, 0.0, 0.0, ), dtype=numpy.float32)

    @property
    def ORIENTATION__DEFAULT(cls):
        """Return default value for message field 'orientation'."""
        return numpy.array((1.0, 0.0, 0.0, 0.0, ), dtype=numpy.float32)

>>>>>>> an

class ImportUsd_Request(metaclass=Metaclass_ImportUsd_Request):
    """Message class 'ImportUsd_Request'."""

    __slots__ = [
        '_name',
        '_usd_path',
        '_prim_path',
        '_control',
<<<<<<< HEAD
=======
        '_position',
        '_orientation',
>>>>>>> an
    ]

    _fields_and_field_types = {
        'name': 'string',
        'usd_path': 'string',
        'prim_path': 'string',
        'control': 'boolean',
<<<<<<< HEAD
=======
        'position': 'float[3]',
        'orientation': 'float[4]',
>>>>>>> an
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
<<<<<<< HEAD
=======
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 4),  # noqa: E501
>>>>>>> an
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.usd_path = kwargs.get('usd_path', str())
        self.prim_path = kwargs.get('prim_path', str())
        self.control = kwargs.get('control', bool())
<<<<<<< HEAD
=======
        self.position = kwargs.get(
            'position', ImportUsd_Request.POSITION__DEFAULT)
        self.orientation = kwargs.get(
            'orientation', ImportUsd_Request.ORIENTATION__DEFAULT)
>>>>>>> an

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
        if self.name != other.name:
            return False
        if self.usd_path != other.usd_path:
            return False
        if self.prim_path != other.prim_path:
            return False
        if self.control != other.control:
            return False
<<<<<<< HEAD
=======
        if all(self.position != other.position):
            return False
        if all(self.orientation != other.orientation):
            return False
>>>>>>> an
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

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

    @builtins.property
    def control(self):
        """Message field 'control'."""
        return self._control

    @control.setter
    def control(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'control' field must be of type 'bool'"
        self._control = value

<<<<<<< HEAD
=======
    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'position' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 3, \
                "The 'position' numpy.ndarray() must have a size of 3"
            self._position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'position' field must be a set or sequence with length 3 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._position = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'orientation' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 4, \
                "The 'orientation' numpy.ndarray() must have a size of 4"
            self._orientation = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'orientation' field must be a set or sequence with length 4 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._orientation = numpy.array(value, dtype=numpy.float32)

>>>>>>> an

# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ImportUsd_Response(type):
    """Metaclass of message 'ImportUsd_Response'."""

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
                'isaacsim_msgs.srv.ImportUsd_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__import_usd__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__import_usd__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__import_usd__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__import_usd__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__import_usd__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImportUsd_Response(metaclass=Metaclass_ImportUsd_Response):
    """Message class 'ImportUsd_Response'."""

    __slots__ = [
        '_ret',
    ]

    _fields_and_field_types = {
        'ret': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ret = kwargs.get('ret', bool())

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
        if self.ret != other.ret:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ret(self):
        """Message field 'ret'."""
        return self._ret

    @ret.setter
    def ret(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ret' field must be of type 'bool'"
        self._ret = value


class Metaclass_ImportUsd(type):
    """Metaclass of service 'ImportUsd'."""

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
                'isaacsim_msgs.srv.ImportUsd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__import_usd

            from isaacsim_msgs.srv import _import_usd
            if _import_usd.Metaclass_ImportUsd_Request._TYPE_SUPPORT is None:
                _import_usd.Metaclass_ImportUsd_Request.__import_type_support__()
            if _import_usd.Metaclass_ImportUsd_Response._TYPE_SUPPORT is None:
                _import_usd.Metaclass_ImportUsd_Response.__import_type_support__()


class ImportUsd(metaclass=Metaclass_ImportUsd):
    from isaacsim_msgs.srv._import_usd import ImportUsd_Request as Request
    from isaacsim_msgs.srv._import_usd import ImportUsd_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
