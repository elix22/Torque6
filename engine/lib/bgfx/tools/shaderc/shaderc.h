/*
 * Copyright 2011-2015 Branimir Karadzic. All rights reserved.
 * License: http://www.opensource.org/licenses/BSD-2-Clause
 */

#ifndef SHADERC_H_HEADER_GUARD
#define SHADERC_H_HEADER_GUARD

#define _BX_TRACE(_format, ...) \
				BX_MACRO_BLOCK_BEGIN \
					if (g_verbose) \
					{ \
						fprintf(stderr, BX_FILE_LINE_LITERAL "" _format "\n", ##__VA_ARGS__); \
					} \
				BX_MACRO_BLOCK_END

#define _BX_WARN(_condition, _format, ...) \
				BX_MACRO_BLOCK_BEGIN \
					if (!(_condition) ) \
					{ \
						BX_TRACE("WARN " _format, ##__VA_ARGS__); \
					} \
				BX_MACRO_BLOCK_END

#define _BX_CHECK(_condition, _format, ...) \
				BX_MACRO_BLOCK_BEGIN \
					if (!(_condition) ) \
					{ \
						BX_TRACE("CHECK " _format, ##__VA_ARGS__); \
						bx::debugBreak(); \
					} \
				BX_MACRO_BLOCK_END

#define BX_TRACE _BX_TRACE
#define BX_WARN  _BX_WARN
#define BX_CHECK _BX_CHECK

#ifndef SHADERC_CONFIG_DIRECT3D9
#	define SHADERC_CONFIG_DIRECT3D9 BX_PLATFORM_WINDOWS
#endif // SHADERC_CONFIG_DIRECT3D9

#ifndef SHADERC_CONFIG_DIRECT3D11
//#	define SHADERC_CONFIG_DIRECT3D11 BX_PLATFORM_WINDOWS
#	define SHADERC_CONFIG_DIRECT3D11 0
#endif // SHADERC_CONFIG_DIRECT3D11

extern bool g_verbose;

#include <alloca.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>

#include <bx/bx.h>
#include <bx/debug.h>
#include <bx/commandline.h>
#include <bx/endian.h>
#include <bx/uint32_t.h>
#include <bx/readerwriter.h>
#include <bx/string.h>
#include <bx/hash.h>
#include "../../src/vertexdecl.h"

struct UniformType
{
	enum Enum
	{
		Uniform1i,
		Uniform1f,
		End,

		Uniform1iv,
		Uniform1fv,
		Uniform2fv,
		Uniform3fv,
		Uniform4fv,
		Uniform3x3fv,
		Uniform4x4fv,

		Count
	};
};

#define BGFX_UNIFORM_FRAGMENTBIT UINT8_C(0x10)

const char* getUniformTypeName(UniformType::Enum _enum);
UniformType::Enum nameToUniformTypeEnum(const char* _name);

struct Uniform
{
	std::string name;
	UniformType::Enum type;
	uint8_t num;
	uint16_t regIndex;
	uint16_t regCount;
};

typedef std::vector<Uniform> UniformArray;

void printCode(const char* _code, int32_t _line = 0, int32_t _start = 0, int32_t _end = INT32_MAX);
void strreplace(char* _str, const char* _find, const char* _replace);
int32_t writef(bx::WriterI* _writer, const char* _format, ...);
void writeFile(const char* _filePath, const void* _data, int32_t _size);

bool compileHLSLShaderDx9(bx::CommandLine& _cmdLine, const std::string& _code, bx::WriterI* _writer);
bool compileHLSLShaderDx11(bx::CommandLine& _cmdLine, const std::string& _code, bx::WriterI* _writer);
bool compileGLSLShader(bx::CommandLine& _cmdLine, uint32_t _gles, const std::string& _code, bx::WriterI* _writer);

// andremwac: Compile Function
int preprocessAndCompile(bx::CommandLine& cmdLine);

#define BGFX_SHADERC_DEBUG                  UINT64_C(0x0000000000000001)
#define BGFX_SHADERC_OPTIMIZE               UINT64_C(0x0000000000000002)
#define BGFX_SHADERC_RAW                    UINT64_C(0x0000000000000004)
#define BGFX_SHADERC_DEPENDS                UINT64_C(0x0000000000000008)
#define BGFX_SHADERC_PREPROCESSONLY         UINT64_C(0x0000000000000010)
#define BGFX_SHADERC_DISASSEMBLEASM         UINT64_C(0x0000000000000020)
#define BGFX_SHADERC_AVOIDFLOWCONTROL       UINT64_C(0x0000000000000040)
#define BGFX_SHADERC_NOPRESHADER            UINT64_C(0x0000000000000080)
#define BGFX_SHADERC_PARTIALPRECISION       UINT64_C(0x0000000000000100)
#define BGFX_SHADERC_PREFERFLOWCONTROL      UINT64_C(0x0000000000000200)
#define BGFX_SHADERC_BACKWARDCOMPAT         UINT64_C(0x0000000000000400)
#define BGFX_SHADERC_WARNINGSAREERRORS      UINT64_C(0x0000000000000800)

namespace bgfx
{

   int compileShader(uint64_t _flags,
                     const char* _filePath,
                     const char* _outFilePath,
                     const char* _type,
                     const char* _platform,
                     const char* _profile,
                     const char* _bin2c,
                     const char* _includeDir,
                     const char* _varyingdef,
                     char* _outputText);

}

#endif // SHADERC_H_HEADER_GUARD
