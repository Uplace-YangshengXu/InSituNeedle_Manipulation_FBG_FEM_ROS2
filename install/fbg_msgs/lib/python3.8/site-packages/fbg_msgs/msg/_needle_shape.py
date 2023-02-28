# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fbg_msgs:msg/NeedleShape.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'active_area_location'
# Member 'needle_x_axis'
# Member 'needle_y_axis'
# Member 'needle_z_axis'
# Member 'needle_slope'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NeedleShape(type):
    """Metaclass of message 'NeedleShape'."""

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
                'fbg_msgs.msg.NeedleShape')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__needle_shape
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__needle_shape
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__needle_shape
            cls._TYPE_SUPPORT = module.type_support_msg__msg__needle_shape
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__needle_shape

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NeedleShape(metaclass=Metaclass_NeedleShape):
    """Message class 'NeedleShape'."""

    __slots__ = [
        '_needle_total_length',
        '_active_area_location',
        '_needle_x_axis',
        '_needle_y_axis',
        '_needle_z_axis',
        '_needle_slope',
    ]

    _fields_and_field_types = {
        'needle_total_length': 'uint8',
        'active_area_location': 'sequence<double>',
        'needle_x_axis': 'sequence<double>',
        'needle_y_axis': 'sequence<double>',
        'needle_z_axis': 'sequence<double>',
        'needle_slope': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.needle_total_length = kwargs.get('needle_total_length', int())
        self.active_area_location = array.array('d', kwargs.get('active_area_location', []))
        self.needle_x_axis = array.array('d', kwargs.get('needle_x_axis', []))
        self.needle_y_axis = array.array('d', kwargs.get('needle_y_axis', []))
        self.needle_z_axis = array.array('d', kwargs.get('needle_z_axis', []))
        self.needle_slope = array.array('d', kwargs.get('needle_slope', []))

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
        if self.needle_total_length != other.needle_total_length:
            return False
        if self.active_area_location != other.active_area_location:
            return False
        if self.needle_x_axis != other.needle_x_axis:
            return False
        if self.needle_y_axis != other.needle_y_axis:
            return False
        if self.needle_z_axis != other.needle_z_axis:
            return False
        if self.needle_slope != other.needle_slope:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def needle_total_length(self):
        """Message field 'needle_total_length'."""
        return self._needle_total_length

    @needle_total_length.setter
    def needle_total_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'needle_total_length' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'needle_total_length' field must be an unsigned integer in [0, 255]"
        self._needle_total_length = value

    @property
    def active_area_location(self):
        """Message field 'active_area_location'."""
        return self._active_area_location

    @active_area_location.setter
    def active_area_location(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'active_area_location' array.array() must have the type code of 'd'"
            self._active_area_location = value
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
                "The 'active_area_location' field must be a set or sequence and each value of type 'float'"
        self._active_area_location = array.array('d', value)

    @property
    def needle_x_axis(self):
        """Message field 'needle_x_axis'."""
        return self._needle_x_axis

    @needle_x_axis.setter
    def needle_x_axis(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'needle_x_axis' array.array() must have the type code of 'd'"
            self._needle_x_axis = value
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
                "The 'needle_x_axis' field must be a set or sequence and each value of type 'float'"
        self._needle_x_axis = array.array('d', value)

    @property
    def needle_y_axis(self):
        """Message field 'needle_y_axis'."""
        return self._needle_y_axis

    @needle_y_axis.setter
    def needle_y_axis(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'needle_y_axis' array.array() must have the type code of 'd'"
            self._needle_y_axis = value
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
                "The 'needle_y_axis' field must be a set or sequence and each value of type 'float'"
        self._needle_y_axis = array.array('d', value)

    @property
    def needle_z_axis(self):
        """Message field 'needle_z_axis'."""
        return self._needle_z_axis

    @needle_z_axis.setter
    def needle_z_axis(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'needle_z_axis' array.array() must have the type code of 'd'"
            self._needle_z_axis = value
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
                "The 'needle_z_axis' field must be a set or sequence and each value of type 'float'"
        self._needle_z_axis = array.array('d', value)

    @property
    def needle_slope(self):
        """Message field 'needle_slope'."""
        return self._needle_slope

    @needle_slope.setter
    def needle_slope(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'needle_slope' array.array() must have the type code of 'd'"
            self._needle_slope = value
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
                "The 'needle_slope' field must be a set or sequence and each value of type 'float'"
        self._needle_slope = array.array('d', value)
