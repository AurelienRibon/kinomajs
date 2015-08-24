/*
 *     Copyright (C) 2010-2015 Marvell International Ltd.
 *     Copyright (C) 2002-2010 Kinoma, Inc.
 *
 *     Licensed under the Apache License, Version 2.0 (the "License");
 *     you may not use this file except in compliance with the License.
 *     You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */
#ifndef __XS6COMMON__
#define __XS6COMMON__

#include "xs6Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef txS1 txByte;
typedef txU1 txFlag;
typedef txS2 txID;
typedef txS4 txIndex;
typedef txS1 txKind;
typedef txS4 txSize;
typedef txS4 txError;

typedef txS4 txBoolean;
typedef txS4 txInteger;
typedef double txNumber;
typedef char* txString;
typedef txU4 txUnsigned;
typedef int (*txGetter)(void*);
typedef int (*txPutter)(txString, void*);

#define XS_ATOM_ARCHIVE 0x58533641 /* 'XS6A' */
#define XS_ATOM_BINARY 0x58533642 /* 'XS6B' */
#define XS_ATOM_CODE 0x434F4445 /* 'CODE' */
#define XS_ATOM_HOSTS 0x484F5354 /* 'HOST' */
#define XS_ATOM_PATHS 0x50415448 /* 'PATH' */
#define XS_ATOM_SYMBOLS 0x53594D42 /* 'SYMB' */
#define XS_ATOM_VERSION 0x56455253 /* 'VERS' */
#define XS_MAJOR_VERSION 6
#define XS_MINOR_VERSION 0
#define XS_PATCH_VERSION 7

typedef struct {
	txS4 atomSize;
	txU4 atomType;
} Atom;

typedef struct {
	void* callback;
	txS1* symbolsBuffer;
	txSize symbolsSize;
	txS1* codeBuffer;
	txSize codeSize;
	txS1* hostsBuffer;
	txSize hostsSize;
	txString path;
	txS1 version[4];
} txScript;

typedef struct {
	txS4 size;
	txU4 cmask;
	txU4 cval;
	txS4 shift;
	txU4 lmask;
	txU4 lval;
} txUTF8Sequence;

enum {
	XS_NO_CODE = 0,
	XS_CODE_ADD,
	XS_CODE_ARGUMENT,
	XS_CODE_ARGUMENTS,
	XS_CODE_ARGUMENTS_SLOPPY,
	XS_CODE_ARGUMENTS_STRICT,
	XS_CODE_ARRAY,
	XS_CODE_ARROW,
	XS_CODE_AT,
	XS_CODE_BEGIN_SLOPPY,
	XS_CODE_BEGIN_STRICT,
	XS_CODE_BEGIN_STRICT_BASE,
	XS_CODE_BEGIN_STRICT_DERIVED,
	XS_CODE_BIT_AND,
	XS_CODE_BIT_NOT,
	XS_CODE_BIT_OR,
	XS_CODE_BIT_XOR,
	XS_CODE_BRANCH_1,
	XS_CODE_BRANCH_2,
	XS_CODE_BRANCH_4,
	XS_CODE_BRANCH_ELSE_1,
	XS_CODE_BRANCH_ELSE_2,
	XS_CODE_BRANCH_ELSE_4,
	XS_CODE_BRANCH_IF_1,
	XS_CODE_BRANCH_IF_2,
	XS_CODE_BRANCH_IF_4,
	XS_CODE_BRANCH_STATUS_1,
	XS_CODE_BRANCH_STATUS_2,
	XS_CODE_BRANCH_STATUS_4,
	XS_CODE_CALL,
	XS_CODE_CALL_TAIL,
	XS_CODE_CATCH_1,
	XS_CODE_CATCH_2,
	XS_CODE_CATCH_4,
	XS_CODE_CLASS,
	XS_CODE_CODE_1,
	XS_CODE_CODE_2,
	XS_CODE_CODE_4,
	XS_CODE_CODE_ARCHIVE_1,
	XS_CODE_CODE_ARCHIVE_2,
	XS_CODE_CODE_ARCHIVE_4,
	XS_CODE_CONST_CLOSURE_1,
	XS_CODE_CONST_CLOSURE_2,
	XS_CODE_CONST_GLOBAL,
	XS_CODE_CONST_LOCAL_1,
	XS_CODE_CONST_LOCAL_2,
	XS_CODE_CURRENT,
	XS_CODE_DEBUGGER,
	XS_CODE_DECREMENT,
	XS_CODE_DELETE_CLOSURE_1,
	XS_CODE_DELETE_CLOSURE_2,
	XS_CODE_DELETE_EVAL,
	XS_CODE_DELETE_GLOBAL,
	XS_CODE_DELETE_LOCAL_1,
	XS_CODE_DELETE_LOCAL_2,
	XS_CODE_DELETE_PROPERTY,
	XS_CODE_DELETE_PROPERTY_AT,
	XS_CODE_DELETE_SUPER,
	XS_CODE_DELETE_SUPER_AT,
	XS_CODE_DIVIDE,
	XS_CODE_DUB,
	XS_CODE_END,
	XS_CODE_EQUAL,
	XS_CODE_EVAL,
	XS_CODE_EXCEPTION,
	XS_CODE_EXTEND,
	XS_CODE_FALSE,
	XS_CODE_FILE,
	XS_CODE_FOR_IN,
	XS_CODE_FOR_OF,
	XS_CODE_FUNCTION,
	XS_CODE_GENERATOR,
	XS_CODE_GET_CLOSURE_1,
	XS_CODE_GET_CLOSURE_2,
	XS_CODE_GET_EVAL,
	XS_CODE_GET_GLOBAL,
	XS_CODE_GET_HOME,
	XS_CODE_GET_LOCAL_1,
	XS_CODE_GET_LOCAL_2,
	XS_CODE_GET_PROPERTY,
	XS_CODE_GET_PROPERTY_AT,
	XS_CODE_GET_SUPER,
	XS_CODE_GET_SUPER_AT,
	XS_CODE_GET_THIS,
	XS_CODE_HOST,
	XS_CODE_IN,
	XS_CODE_INCREMENT,
	XS_CODE_INSTANCEOF,
	XS_CODE_INSTANTIATE,
	XS_CODE_INTEGER_1,
	XS_CODE_INTEGER_2,
	XS_CODE_INTEGER_4,
	XS_CODE_LEFT_SHIFT,
	XS_CODE_LESS,
	XS_CODE_LESS_EQUAL,
	XS_CODE_LINE,
	XS_CODE_MINUS,
	XS_CODE_MODULE,
	XS_CODE_MODULO,
	XS_CODE_MORE,
	XS_CODE_MORE_EQUAL,
	XS_CODE_MULTIPLY,
	XS_CODE_NEW,
	XS_CODE_NEW_CLOSURE,
	XS_CODE_NEW_EVAL,
	XS_CODE_NEW_GLOBAL,
	XS_CODE_NEW_LOCAL,
	XS_CODE_NEW_PROPERTY,
	XS_CODE_NEW_TEMPORARY,
	XS_CODE_NOT,
	XS_CODE_NOT_EQUAL,
	XS_CODE_NULL,
	XS_CODE_NUMBER,
	XS_CODE_OBJECT,
	XS_CODE_PLUS,
	XS_CODE_POP,
	XS_CODE_PULL_CLOSURE_1,
	XS_CODE_PULL_CLOSURE_2,
	XS_CODE_PULL_LOCAL_1,
	XS_CODE_PULL_LOCAL_2,
	XS_CODE_RESULT,
	XS_CODE_RESERVE_1,
	XS_CODE_RESERVE_2,
	XS_CODE_RETHROW,
	XS_CODE_RETRIEVE_1,
	XS_CODE_RETRIEVE_2,
	XS_CODE_RETRIEVE_TARGET,
	XS_CODE_RETRIEVE_THIS,
	XS_CODE_RETURN,
	XS_CODE_SCOPE,
	XS_CODE_SET_CLOSURE_1,
	XS_CODE_SET_CLOSURE_2,
	XS_CODE_SET_EVAL,
	XS_CODE_SET_GLOBAL,
	XS_CODE_SET_HOME,
	XS_CODE_SET_LOCAL_1,
	XS_CODE_SET_LOCAL_2,
	XS_CODE_SET_PROPERTY,
	XS_CODE_SET_PROPERTY_AT,
	XS_CODE_SET_SUPER,
	XS_CODE_SET_SUPER_AT,
	XS_CODE_SET_THIS,
	XS_CODE_SIGNED_RIGHT_SHIFT,
	XS_CODE_START,
	XS_CODE_STORE_1,
	XS_CODE_STORE_2,
	XS_CODE_STORE_TARGET,
	XS_CODE_STORE_THIS,
	XS_CODE_STRICT_EQUAL,
	XS_CODE_STRICT_NOT_EQUAL,
	XS_CODE_STRING_1,
	XS_CODE_STRING_2,
	XS_CODE_STRING_ARCHIVE_1,
	XS_CODE_STRING_ARCHIVE_2,
	XS_CODE_SUBTRACT,
	XS_CODE_SUPER,
	XS_CODE_SWAP,
	XS_CODE_SYMBOL,
	XS_CODE_TARGET,
	XS_CODE_THROW,
	XS_CODE_TRANSFER,
	XS_CODE_TRUE,
	XS_CODE_TYPEOF,
	XS_CODE_UNCATCH,
	XS_CODE_UNDEFINED,
	XS_CODE_UNSIGNED_RIGHT_SHIFT,
	XS_CODE_UNWIND_1,
	XS_CODE_UNWIND_2,
	XS_CODE_VOID,
	XS_CODE_WITH,
	XS_CODE_WITHOUT,
	XS_CODE_YIELD,
	XS_CODE_COUNT
};

extern const txS1 gxCodeSizes[XS_CODE_COUNT];

enum {
	XS_DONT_DELETE_FLAG = 2,
	XS_DONT_ENUM_FLAG = 4,
	XS_DONT_SET_FLAG = 8,
	XS_STATIC_FLAG = 16,
	XS_GETTER_FLAG = 32,
	XS_SETTER_FLAG = 64,
};

enum {
	mxCFlag = 1 << 0,
	mxDebugFlag = 1 << 1,
	mxEvalFlag = 1 << 2,
	mxProgramFlag = 1 << 3,
	
	mxParserFlags = mxCFlag | mxDebugFlag | mxEvalFlag | mxProgramFlag,
	
	mxStrictFlag = 1 << 4,
	
	mxArgumentsFlag = 1 << 5,
	mxArrowFlag = 1 << 6,
	mxBaseFlag = 1 << 7,
	mxDerivedFlag = 1 << 8,
	mxFunctionFlag = 1 << 9,
	mxGeneratorFlag = 1 << 10,
	mxGetterFlag = 1 << 11,
	mxSetterFlag = 1 << 12,
	mxShorthandFlag = 1 << 13,
	mxSpreadFlag = 1 << 14,
	mxStaticFlag = 1 << 15,
	mxSuperFlag = 1 << 16,
	mxExpressionNoValue = 1 << 17,
	
	mxCommonModuleFlag = 1 << 18,
	mxCommonProgramFlag = 1 << 19,
	mxDefaultFlag = 1 << 20,
	mxForFlag = 1 << 21,
	
	mxDeclareNodeClosureFlag = 1 << 18,
	mxDeclareNodeUseClosureFlag = 1 << 19,
	mxDeclareNodeInitializedFlag = 1 << 20,
	mxDeclareNodeBoundFlag = 1 << 21,
	mxDefineNodeBoundFlag = 1 << 22,
	mxDefineNodeCodedFlag = 1 << 23,
	
	mxTailRecursionFlag = 1 << 24,
};

extern const txString gxCodeNames[XS_CODE_COUNT];
extern const txUTF8Sequence gxUTF8Sequences[];

extern void fxDeleteScript(txScript* script);

extern txBoolean fxIsIdentifier(txString string);
extern txBoolean fxIsIdentifierFirst(char c);
extern txBoolean fxIsIdentifierNext(char c);
extern txU1* fsX2UTF8(txU4 c, txU1* p, txU4 theSize);

txFlag fxIntegerToIndex(void* dtoa, txInteger theInteger, txIndex* theIndex);
txFlag fxNumberToIndex(void* dtoa, txNumber theNumber, txIndex* theIndex);
txFlag fxStringToIndex(void* dtoa, txString theString, txIndex* theIndex);

/* ? */
extern void fxVReport(void* console, txString theFormat, c_va_list theArguments);
extern void fxVReportError(void* console, txString thePath, txInteger theLine, txString theFormat, c_va_list theArguments);
extern void fxVReportWarning(void* console, txString thePath, txInteger theLine, txString theFormat, c_va_list theArguments);

/* xs_dtoa.c */
extern void* fxNew_dtoa();
extern void fxDelete_dtoa(void*);
extern txString fxIntegerToString(void* dtoa, txInteger theValue, txString theBuffer, txSize theSize);
extern txString fxNumberToString(void* dtoa, txNumber theValue, txString theBuffer, txSize theSize, txByte theMode, txInteger thePrecision);
extern txNumber fxStringToNumber(void* dtoa, txString theString, txFlag whole);

#if mxLittleEndian
#define mxDecode2(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE) + 1; \
	*dst-- = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
	}
#else
#define mxDecode2(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
	}
#endif

#if mxLittleEndian
#define mxDecode4(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE) + 3; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
	}
#else
#define mxDecode4(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
	}
#endif

#if mxLittleEndian
#define mxDecode8(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE) + 7; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst-- = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
}
#else
#define mxDecode8(THE_CODE, THE_VALUE)	{ \
	txS1* src = (THE_CODE); \
	txS1* dst = (txS1*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst = *src++; \
	(THE_CODE) = src; \
	}
#endif

#if mxLittleEndian
#define mxEncode2(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE) + 1; \
	*dst++ = *src--; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#else
#define mxEncode2(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#endif

#if mxLittleEndian
#define mxEncode4(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE) + 3; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#else
#define mxEncode4(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#endif

#if mxLittleEndian
#define mxEncode8(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE) + 7; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src--; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#else
#define mxEncode8(THE_CODE, THE_VALUE)	{ \
	txByte* dst = (THE_CODE); \
	txByte* src = (txByte*)&(THE_VALUE); \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src++; \
	*dst++ = *src; \
	(THE_CODE) = dst; \
	}
#endif

#define XS_NO_ID -1
enum {
	_Symbol_hasInstance = 1,
	_Symbol_isConcatSpreadable,
	_Symbol_iterator,
	_Symbol_match,
	_Symbol_replace,
	_Symbol_search,
	_Symbol_species,
	_Symbol_split,
	_Symbol_toPrimitive,
	_Symbol_toStringTag,
	_Symbol_unscopables,
	___proto__,
	__default_,
	_Array,
	_ArrayBuffer,
	_BYTES_PER_ELEMENT,
	_Boolean,
	_Chunk,
	_DataView,
	_Date,
	_E,
	_EPSILON,
	_Error,
	_EvalError,
	_Float32Array,
	_Float64Array,
	_Function,
	_Generator,
	_GeneratorFunction,
	_Infinity,
	_Int16Array,
	_Int32Array,
	_Int8Array,
	_JSON,
	_LN10,
	_LN2,
	_LOG10E,
	_LOG2E,
	_MAX_SAFE_INTEGER,
	_MAX_VALUE,
	_MIN_SAFE_INTEGER,
	_MIN_VALUE,
	_Map,
	_Math,
	_NEGATIVE_INFINITY,
	_NaN,
	_Number,
	_Object,
	_PI,
	_POSITIVE_INFINITY,
	_Promise,
	_Proxy,
	_RangeError,
	_ReferenceError,
	_Reflect,
	_RegExp,
	_SQRT1_2,
	_SQRT2,
	_Set,
	_String,
	_Symbol,
	_SyntaxError,
	_TypeError,
	_URIError,
	_UTC,
	_Uint16Array,
	_Uint32Array,
	_Uint8Array,
	_Uint8ClampedArray,
	_WeakMap,
	_WeakSet,
	_abs,
	_acos,
	_acosh,
	_add,
	_aliases,
	_all,
	_append,
	_apply,
	_arguments,
	_asin,
	_asinh,
	_assign,
	_atan,
	_atanh,
	_atan2,
	_bind,
	_boundArguments,
	_boundFunction,
	_boundThis,
	_buffer,
	_busy,
	_byteLength,
	_byteOffset,
	_call,
	_callee,
	_caller,
	_catch,
	_cbrt,
	_ceil,
	_charAt,
	_charCodeAt,
	_chunk,
	_chunkify,
	_clear,
	_closure,
	_clz32,
	_codePointAt,
	_compare,
	_compile,
	_concat,
	_configurable,
	_console,
	_construct,
	_constructor,
	_copyWithin,
	_cos,
	_cosh,
	_count,
	_create,
	_decodeURI,
	_decodeURIComponent,
	_default,
	_defineProperties,
	_defineProperty,
	_delete,
	_deleteProperty,
	_done,
	_eachDown,
	_eachUp,
	_encodeURI,
	_encodeURIComponent,
	_endsWith,
	_entries,
	_enumerable,
	_enumerate,
	_escape,
	_eval,
	_every,
	_exec,
	_exp,
	_expm1,
	_exports,
	_fill,
	_filter,
	_find,
	_findIndex,
	_flags,
	_floor,
	_for,
	_forEach,
	_free,
	_freeze,
	_from,
	_fromArrayBuffer,
	_fromCharCode,
	_fromCodePoint,
	_fromString,
	_fround,
	_function,
	_get,
	_getDate,
	_getDay,
	_getFloat32,
	_getFloat64,
	_getFullYear,
	_getHours,
	_getInt16,
	_getInt32,
	_getInt8,
	_getMilliseconds,
	_getMinutes,
	_getMonth,
	_getOwnPropertyDescriptor,
	_getOwnPropertyNames,
	_getOwnPropertySymbols,
	_getPrototypeOf,
	_getSeconds,
	_getTime,
	_getTimezoneOffset,
	_getUTCDate,
	_getUTCDay,
	_getUTCFullYear,
	_getUTCHours,
	_getUTCMilliseconds,
	_getUTCMinutes,
	_getUTCMonth,
	_getUTCSeconds,
	_getUint16,
	_getUint32,
	_getUint8,
	_getUint8Clamped,
	_getYear,
	_global,
	_has,
	_hasInstance,
	_hasOwnProperty,
	_hypot_,
	_id,
	_ignoreCase,
	_import,
	_imul,
	_includes,
	_index,
	_indexOf,
	_input,
	_is,
	_isArray,
	_isConcatSpreadable,
	_isExtensible,
	_isFinite,
	_isFrozen,
	_isInteger,
	_isNaN,
	_isPrototypeOf,
	_isSafeInteger,
	_isSealed,
	_isView,
	_iterable,
	_iterator,
	_join,
	_keyFor,
	_keys,
	_lastIndex,
	_lastIndexOf,
	_length,
	_line,
	_local,
	_localeCompare,
	_log,
	_log1p,
	_log10,
	_log2,
	_map,
	_match,
	_max,
	_message,
	_min,
	_multiline,
	_name,
	_next,
	_normalize,
	_now,
	_of,
	_ownKeys,
	_parse,
	_parseFloat,
	_parseInt,
	_path,
	_peek,
	_poke,
	_pop,
	_pow,
	_preventExtensions,
	_propertyIsEnumerable,
	_propertyIsScriptable,
	_prototype,
	_proxy,
	_push,
	_race,
	_random,
	_raw,
	_reduce,
	_reduceRight,
	_reject,
	_repeat,
	_replace,
	_require,
	_resolve,
	_result,
	_return,
	_reverse,
	_revocable,
	_revoke,
	_round,
	_seal,
	_search,
	_serialize,
	_set,
	_setDate,
	_setFloat32,
	_setFloat64,
	_setFullYear,
	_setHours,
	_setInt16,
	_setInt32,
	_setInt8,
	_setMilliseconds,
	_setMinutes,
	_setMonth,
	_setPrototypeOf,
	_setSeconds,
	_setTime,
	_setTimeout,
	_setUTCDate,
	_setUTCFullYear,
	_setUTCHours,
	_setUTCMilliseconds,
	_setUTCMinutes,
	_setUTCMonth,
	_setUTCSeconds,
	_setUint16,
	_setUint32,
	_setUint8,
	_setUint8Clamped,
	_setYear,
	_shift,
	_sign,
	_sin,
	_sinh,
	_size,
	_slice,
	_some,
	_sort,
	_source,
	_species,
	_splice,
	_split,
	_sqrt,
	_startsWith,
	_sticky,
	_stringify,
	_subarray,
	_substr,
	_substring,
	_tan,
	_tanh,
	_test,
	_then,
	_this,
	_throw,
	_toDateString,
	_toExponential,
	_toFixed,
	_toGMTString,
	_toISOString,
	_toJSON,
	_toLocaleDateString,
	_toLocaleLowerCase,
	_toLocaleString,
	_toLocaleTimeString,
	_toLocaleUpperCase,
	_toLowerCase,
	_toPrecision,
	_toPrimitive,
	_toString,
	_toStringTag,
	_toTimeString,
	_toUTCString,
	_toUpperCase,
	_trace,
	_transfers,
	_trim,
	_trunc,
	_undefined,
	_unescape,
	_unicode,
	_unscopables,
	_unshift,
	_uri,
	_value,
	_valueOf,
	_values,
	_weak,
	_writable,
	XS_ID_COUNT
};
#define XS_SYMBOL_ID_COUNT ___proto__
#if defined(mxParse) || defined(mxLink) || defined(__FSK_LAYER__)
extern const txString gxIDStrings[XS_ID_COUNT];
#endif

#ifdef __cplusplus
}
#endif

#endif /* __XS6COMMON__ */