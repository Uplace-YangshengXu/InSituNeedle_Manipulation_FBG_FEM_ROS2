# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fbg_msgs:srv/Curvature.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Curvature_Request(type):
    """Metaclass of message 'Curvature_Request'."""

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
            module = import_type_support('fbg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fbg_msgs.srv.Curvature_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__curvature__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__curvature__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__curvature__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__curvature__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__curvature__request

            from fbg_msgs.msg import FbgReading
            if FbgReading.__class__._TYPE_SUPPORT is None:
                FbgReading.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Curvature_Request(metaclass=Metaclass_Curvature_Request):
    """Message class 'Curvature_Request'."""

    __slots__ = [
        '_fbg_reading',
    ]

    _fields_and_field_types = {
        'fbg_reading': 'fbg_msgs/FbgReading',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['fbg_msgs', 'msg'], 'FbgReading'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from fbg_msgs.msg import FbgReading
        self.fbg_reading = kwargs.get('fbg_reading', FbgReading())

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
        if self.fbg_reading != other.fbg_reading:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def fbg_reading(self):
        """Message field 'fbg_reading'."""
        return self._fbg_reading

    @fbg_reading.setter
    def fbg_reading(self, value):
        if __debug__:
            from fbg_msgs.msg import FbgReading
            assert \
                isinstance(value, FbgReading), \
                "The 'fbg_reading' field must be a sub message of type 'FbgReading'"
        self._fbg_reading = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_Curvature_Response(type):
    """Metaclass of message 'Curvature_Response'."""

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
            module = import_type_support('fbg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fbg_msgs.srv.Curvature_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__curvature__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__curvature__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__curvature__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__curvature__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__curvature__response

            from fbg_msgs.msg import Curvature
            if Curvature.__class__._TYPE_SUPPORT is None:
                Curvature.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Curvature_Response(metaclass=Metaclass_Curvature_Response):
    """Message class 'Curvature_Response'."""

    __slots__ = [
        '_curvature',
    ]

    _fields_and_field_types = {
        'curvature': 'fbg_msgs/Curvature',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['fbg_msgs', 'msg'], 'Curvature'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from fbg_msgs.msg import Curvature
        self.curvature = kwargs.get('curvature', Curvature())

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
        if self.curvature != other.curvature:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def curvature(self):
        """Message field 'curvature'."""
        return self._curvature

    @curvature.setter
    def curvature(self, value):
        if __debug__:
            from fbg_msgs.msg import Curvature
            assert \
                isinstance(value, Curvature), \
                "The 'curvature' field must be a sub message of type 'Curvature'"
        self._curvature = value


class Metaclass_Curvature(type):
    """Metaclass of service 'Curvature'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fbg_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fbg_msgs.srv.Curvature')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__curvature

            from fbg_msgs.srv import _curvature
            if _curvature.Metaclass_Curvature_Request._TYPE_SUPPORT is None:
                _curvature.Metaclass_Curvature_Request.__import_type_support__()
            if _curvature.Metaclass_Curvature_Response._TYPE_SUPPORT is None:
                _curvature.Metaclass_Curvature_Response.__import_type_support__()


class Curvature(metaclass=Metaclass_Curvature):
    from fbg_msgs.srv._curvature import Curvature_Request as Request
    from fbg_msgs.srv._curvature import Curvature_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
