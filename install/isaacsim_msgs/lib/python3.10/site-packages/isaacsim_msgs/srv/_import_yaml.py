# generated from rosidl_generator_py/resource/_idl.py.em
# with input from isaacsim_msgs:srv/ImportYaml.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImportYaml_Request(type):
    """Metaclass of message 'ImportYaml_Request'."""

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
                'isaacsim_msgs.srv.ImportYaml_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__import_yaml__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__import_yaml__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__import_yaml__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__import_yaml__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__import_yaml__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImportYaml_Request(metaclass=Metaclass_ImportYaml_Request):
    """Message class 'ImportYaml_Request'."""

    __slots__ = [
        '_yaml_path',
    ]

    _fields_and_field_types = {
        'yaml_path': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.yaml_path = kwargs.get('yaml_path', str())

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
        if self.yaml_path != other.yaml_path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def yaml_path(self):
        """Message field 'yaml_path'."""
        return self._yaml_path

    @yaml_path.setter
    def yaml_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'yaml_path' field must be of type 'str'"
        self._yaml_path = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ImportYaml_Response(type):
    """Metaclass of message 'ImportYaml_Response'."""

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
                'isaacsim_msgs.srv.ImportYaml_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__import_yaml__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__import_yaml__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__import_yaml__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__import_yaml__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__import_yaml__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImportYaml_Response(metaclass=Metaclass_ImportYaml_Response):
    """Message class 'ImportYaml_Response'."""

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


class Metaclass_ImportYaml(type):
    """Metaclass of service 'ImportYaml'."""

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
                'isaacsim_msgs.srv.ImportYaml')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__import_yaml

            from isaacsim_msgs.srv import _import_yaml
            if _import_yaml.Metaclass_ImportYaml_Request._TYPE_SUPPORT is None:
                _import_yaml.Metaclass_ImportYaml_Request.__import_type_support__()
            if _import_yaml.Metaclass_ImportYaml_Response._TYPE_SUPPORT is None:
                _import_yaml.Metaclass_ImportYaml_Response.__import_type_support__()


class ImportYaml(metaclass=Metaclass_ImportYaml):
    from isaacsim_msgs.srv._import_yaml import ImportYaml_Request as Request
    from isaacsim_msgs.srv._import_yaml import ImportYaml_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
