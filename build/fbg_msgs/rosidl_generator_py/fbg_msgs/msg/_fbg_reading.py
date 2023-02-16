# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fbg_msgs:msg/FbgReading.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'signal_reading'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FbgReading(type):
    """Metaclass of message 'FbgReading'."""

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
                'fbg_msgs.msg.FbgReading')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fbg_reading
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fbg_reading
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fbg_reading
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fbg_reading
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fbg_reading

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FbgReading(metaclass=Metaclass_FbgReading):
    """Message class 'FbgReading'."""

    __slots__ = [
        '_num_channel',
        '_num_aa',
        '_signal_reading',
    ]

    _fields_and_field_types = {
        'num_channel': 'uint16',
        'num_aa': 'uint16',
        'signal_reading': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.num_channel = kwargs.get('num_channel', int())
        self.num_aa = kwargs.get('num_aa', int())
        self.signal_reading = array.array('d', kwargs.get('signal_reading', []))

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
        if self.num_channel != other.num_channel:
            return False
        if self.num_aa != other.num_aa:
            return False
        if self.signal_reading != other.signal_reading:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def num_channel(self):
        """Message field 'num_channel'."""
        return self._num_channel

    @num_channel.setter
    def num_channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_channel' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'num_channel' field must be an unsigned integer in [0, 65535]"
        self._num_channel = value

    @property
    def num_aa(self):
        """Message field 'num_aa'."""
        return self._num_aa

    @num_aa.setter
    def num_aa(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_aa' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'num_aa' field must be an unsigned integer in [0, 65535]"
        self._num_aa = value

    @property
    def signal_reading(self):
        """Message field 'signal_reading'."""
        return self._signal_reading

    @signal_reading.setter
    def signal_reading(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'signal_reading' array.array() must have the type code of 'd'"
            self._signal_reading = value
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
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'signal_reading' field must be a set or sequence and each value of type 'float'"
        self._signal_reading = array.array('d', value)
