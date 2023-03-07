# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fbg_msgs:msg/Curvature.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'curvature_xy'
# Member 'curvature_xz'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Curvature(type):
    """Metaclass of message 'Curvature'."""

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
                'fbg_msgs.msg.Curvature')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__curvature
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__curvature
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__curvature
            cls._TYPE_SUPPORT = module.type_support_msg__msg__curvature
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__curvature

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Curvature(metaclass=Metaclass_Curvature):
    """Message class 'Curvature'."""

    __slots__ = [
        '_curvature_xy',
        '_curvature_xz',
    ]

    _fields_and_field_types = {
        'curvature_xy': 'sequence<double>',
        'curvature_xz': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.curvature_xy = array.array('d', kwargs.get('curvature_xy', []))
        self.curvature_xz = array.array('d', kwargs.get('curvature_xz', []))

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
        if self.curvature_xy != other.curvature_xy:
            return False
        if self.curvature_xz != other.curvature_xz:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def curvature_xy(self):
        """Message field 'curvature_xy'."""
        return self._curvature_xy

    @curvature_xy.setter
    def curvature_xy(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'curvature_xy' array.array() must have the type code of 'd'"
            self._curvature_xy = value
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
                "The 'curvature_xy' field must be a set or sequence and each value of type 'float'"
        self._curvature_xy = array.array('d', value)

    @property
    def curvature_xz(self):
        """Message field 'curvature_xz'."""
        return self._curvature_xz

    @curvature_xz.setter
    def curvature_xz(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'curvature_xz' array.array() must have the type code of 'd'"
            self._curvature_xz = value
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
                "The 'curvature_xz' field must be a set or sequence and each value of type 'float'"
        self._curvature_xz = array.array('d', value)
