#ifndef ASSIGNMENT1_MSGS__VISIBILITY_CONTROL_H_
#define ASSIGNMENT1_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ASSIGNMENT1_MSGS_EXPORT __attribute__ ((dllexport))
    #define ASSIGNMENT1_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define ASSIGNMENT1_MSGS_EXPORT __declspec(dllexport)
    #define ASSIGNMENT1_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef ASSIGNMENT1_MSGS_BUILDING_LIBRARY
    #define ASSIGNMENT1_MSGS_PUBLIC ASSIGNMENT1_MSGS_EXPORT
  #else
    #define ASSIGNMENT1_MSGS_PUBLIC ASSIGNMENT1_MSGS_IMPORT
  #endif
  #define ASSIGNMENT1_MSGS_PUBLIC_TYPE ASSIGNMENT1_MSGS_PUBLIC
  #define ASSIGNMENT1_MSGS_LOCAL
#else
  #define ASSIGNMENT1_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define ASSIGNMENT1_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define ASSIGNMENT1_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define ASSIGNMENT1_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ASSIGNMENT1_MSGS_PUBLIC
    #define ASSIGNMENT1_MSGS_LOCAL
  #endif
  #define ASSIGNMENT1_MSGS_PUBLIC_TYPE
#endif
#endif  // ASSIGNMENT1_MSGS__VISIBILITY_CONTROL_H_
// Generated 23-Feb-2023 16:13:58
 