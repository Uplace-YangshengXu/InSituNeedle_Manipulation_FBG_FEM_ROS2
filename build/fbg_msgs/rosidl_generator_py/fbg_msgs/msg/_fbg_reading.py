# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fbg_msgs:msg/FbgReading.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'signal_reading'
import array  # noqa: E402, I100

# Member 'signal_each_ch'
import numpy  # noqa: E402, I100

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
        '_signal_reading',
        '_signal_each_ch',
        '_total_reading_num',
    ]

    _fields_and_field_types = {
        'signal_reading': 'sequence<double>',
        'signal_each_ch': 'uint8[4]',
        'total_reading_num': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.signal_reading = array.array('d', kwargs.get('signal_reading', []))
        if 'signal_each_ch' not in kwargs:
            self.signal_each_ch = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.signal_each_ch = numpy.array(kwargs.get('signal_each_ch'), dtype=numpy.uint8)
            assert self.signal_each_ch.shape == (4, )
        self.total_reading_num = kwargs.get('total_reading_num', int())

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
        if self.signal_reading != other.signal_reading:
            return False
        if all(self.signal_each_ch != other.signal_each_ch):
            return False
        if self.total_reading_num != other.total_reading_num:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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

    @property
    def signal_each_ch(self):
        """Message field 'signal_each_ch'."""
        return self._signal_each_ch

    @signal_each_ch.setter
    def signal_each_ch(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'signal_each_ch' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'signal_each_ch' numpy.ndarray() must have a size of 4"
            self._signal_each_ch = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'signal_each_ch' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._signal_each_ch = numpy.array(value, dtype=numpy.uint8)

    @property
    def total_reading_num(self):
        """Message field 'total_reading_num'."""
        return self._total_reading_num

    @total_reading_num.setter
    def total_reading_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total_reading_num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'total_reading_num' field must be an unsigned integer in [0, 255]"
        self._total_reading_num = value
