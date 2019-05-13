#pragma once

#define PP_NARG(...) \
         PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
         PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define PP_RSEQ_N() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#define PARAMS1()
#define PARAMS2(t) t _1
#define PARAMS3(t1, t2) t1 _1, t2 _2
#define PARAMS4(t1, t2, t3) t1 _1, t2 _2, t3 _3
#define PARAMS5(t1, t2, t3, t4) t1 _1, t2 _2, t3 _3, t4 _4
#define PARAMS6(t1, t2, t3, t4, t5) t1 _1, t2 _2, t3 _3, t4 _4, t5 _5
#define PARAMS7(t1, t2, t3, t4, t5, t6) t1 _1, t2 _2, t3 _3, t4 _4, t5 _5, t6 _6
#define PARAMS8(t1, t2, t3, t4, t5, t6, t7) t1 _1, t2 _2, t3 _3, t4 _4, t5 _5, t6 _6, t7 _7
#define NARGS1
#define NARGS2 _1
#define NARGS3 _1, _2
#define NARGS4 _1, _2, _3
#define NARGS5 _1, _2, _3, _4
#define NARGS6 _1, _2, _3, _4, _5
#define NARGS7 _1, _2, _3, _4, _5, _6
#define NARGS8 _1, _2, _3, _4, _5, _6, _7
#define ARGS1
#define ARGS2 , NARGS2
#define ARGS3 , NARGS3
#define ARGS4 , NARGS4
#define ARGS5 , NARGS5
#define ARGS6 , NARGS6
#define ARGS7 , NARGS7
#define ARGS8 , NARGS8
#define CAT(a, b) a##b
#define EV(a, b) CAT(a, b)
