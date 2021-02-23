## This file is NOT licensed under the GPLv3, which is the license for the rest
## of YouCompleteMe.
##
## Here's the license text for this file:
##
## This is free and unencumbered software released into the public domain.
##
## Anyone is free to copy, modify, publish, use, compile, sell, or
## distribute this software, either in source code form or as a compiled
## binary, for any purpose, commercial or non-commercial, and by any
## means.
##
## In jurisdictions that recognize copyright laws, the author or authors
## of this software dedicate any and all copyright interest in the
## software to the public domain. We make this dedication for the benefit
## of the public at large and to the detriment of our heirs and
## successors. We intend this dedication to be an overt act of
## relinquishment in perpetuity of all present and future rights to this
## software under copyright law.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
## EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
## MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
## IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
## OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
## ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
## OTHER DEALINGS IN THE SOFTWARE.
##
## For more information, please refer to <http://unlicense.org/>

#from distutils.sysconfig import get_python_inc
#import platform
#import os.path as p
#import subprocess

#DIR_OF_THIS_SCRIPT = p.abspath( p.dirname( __file__ ) )
#DIR_OF_THIRD_PARTY = p.join( DIR_OF_THIS_SCRIPT, 'third_party' )
#DIR_OF_WATCHDOG_DEPS = p.join( DIR_OF_THIRD_PARTY, 'watchdog_deps' )
#SOURCE_EXTENSIONS = [ '.cpp', '.cxx', '.cc', '.c', '.m', '.mm' ]

#database = None

## These are the compilation flags that will be used in case there's no
## compilation database set (by default, one is not set).
## CHANGE THIS LIST OF FLAGS. YES, THIS IS THE DROID YOU HAVE BEEN LOOKING FOR.
#flags = [
#'-Wall',
#'-Wextra',
#'-Werror',
#'-Wno-long-long',
#'-Wno-variadic-macros',
#'-fexceptions',
#'-DNDEBUG',
## You 100% do NOT need -DUSE_CLANG_COMPLETER and/or -DYCM_EXPORT in your flags;
## only the YCM source code needs it.
#'-DUSE_CLANG_COMPLETER',
#'-DYCM_EXPORT=',
## THIS IS IMPORTANT! Without the '-x' flag, Clang won't know which language to
## use when compiling headers. So it will guess. Badly. So C++ headers will be
## compiled as C headers. You don't want that so ALWAYS specify the '-x' flag.
## For a C project, you would set this to 'c' instead of 'c++'.
#'-x',
#'c++',
#'-isystem',
#'cpp/pybind11',
#'-isystem',
#'cpp/whereami',
#'-isystem',
#'cpp/BoostParts',
#'-isystem',
#get_python_inc(),
#'-isystem',
#'cpp/llvm/include',
#'-isystem',
#'cpp/llvm/tools/clang/include',
#'-I',
#'cpp/ycm',
#'-I',
#'cpp/ycm/ClangCompleter',
#'-isystem',
#'cpp/ycm/tests/gmock/googlemock/include',
#'-isystem',
#'cpp/ycm/tests/gmock/googletest/include',
#'-isystem',
#'cpp/ycm/benchmarks/benchmark/include',
#'-std=c++17',
## '-Wno-unknown-pragmas',
#'-Wno-#pragma-messages'
#]

## Set this to the absolute path to the folder (NOT the file!) containing the
## compile_commands.json file to use that instead of 'flags'. See here for
## more details: http://clang.llvm.org/docs/JSONCompilationDatabase.html
##
## You can get CMake to generate this file for you by adding:
##   set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
## to your CMakeLists.txt file.
##
## Most projects will NOT need to set this to anything; you can just change the
## 'flags' list of compilation flags. Notice that YCM itself uses that approach.
#compilation_database_folder = ''


#def IsHeaderFile( filename ):
#  extension = p.splitext( filename )[ 1 ]
#  return extension in [ '.h', '.hxx', '.hpp', '.hh' ]


#def FindCorrespondingSourceFile( filename ):
#  if IsHeaderFile( filename ):
#    basename = p.splitext( filename )[ 0 ]
#    for extension in SOURCE_EXTENSIONS:
#      replacement_file = basename + extension
#      if p.exists( replacement_file ):
#        return replacement_file
#  return filename


#def PathToPythonUsedDuringBuild():
#  try:
#    filepath = p.join( DIR_OF_THIS_SCRIPT, 'PYTHON_USED_DURING_BUILDING' )
#    with open( filepath ) as f:
#      return f.read().strip()
#  except OSError:
#    return None


#def Settings( **kwargs ):
#  # Do NOT import ycm_core at module scope.
#  import ycm_core

#  global database
#  if database is None and p.exists( compilation_database_folder ):
#    database = ycm_core.CompilationDatabase( compilation_database_folder )

#  language = kwargs[ 'language' ]

#  if language == 'cfamily':
#    # If the file is a header, try to find the corresponding source file and
#    # retrieve its flags from the compilation database if using one. This is
#    # necessary since compilation databases don't have entries for header files.
#    # In addition, use this source file as the translation unit. This makes it
#    # possible to jump from a declaration in the header file to its definition
#    # in the corresponding source file.
#    filename = FindCorrespondingSourceFile( kwargs[ 'filename' ] )

#    if not database:
#      return {
#        'flags': flags,
#        'include_paths_relative_to_dir': DIR_OF_THIS_SCRIPT,
#        'override_filename': filename
#      }

#    compilation_info = database.GetCompilationInfoForFile( filename )
#    if not compilation_info.compiler_flags_:
#      return {}

#    # Bear in mind that compilation_info.compiler_flags_ does NOT return a
#    # python list, but a "list-like" StringVec object.
#    final_flags = list( compilation_info.compiler_flags_ )

#    # NOTE: This is just for YouCompleteMe; it's highly likely that your project
#    # does NOT need to remove the stdlib flag. DO NOT USE THIS IN YOUR
#    # ycm_extra_conf IF YOU'RE NOT 100% SURE YOU NEED IT.
#    try:
#      final_flags.remove( '-stdlib=libc++' )
#    except ValueError:
#      pass

#    return {
#      'flags': final_flags,
#      'include_paths_relative_to_dir': compilation_info.compiler_working_dir_,
#      'override_filename': filename
#    }

#  if language == 'python':
#    return {
#      'interpreter_path': PathToPythonUsedDuringBuild()
#    }

#  return {}


#def PythonSysPath( **kwargs ):
#  sys_path = kwargs[ 'sys_path' ]

#  interpreter_path = kwargs[ 'interpreter_path' ]
#  major_version = subprocess.check_output( [
#    interpreter_path, '-c', 'import sys; print( sys.version_info[ 0 ] )' ]
#  ).rstrip().decode( 'utf8' )

#  sys_path[ 0:0 ] = [ p.join( DIR_OF_THIS_SCRIPT ),
#                      p.join( DIR_OF_THIRD_PARTY, 'bottle' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'regex-build' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'frozendict' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'jedi_deps', 'jedi' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'jedi_deps', 'parso' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'requests_deps', 'requests' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'requests_deps',
#                                                  'urllib3',
#                                                  'src' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'requests_deps',
#                                                  'chardet' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'requests_deps',
#                                                  'certifi' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'requests_deps',
#                                                  'idna' ),
#                      p.join( DIR_OF_WATCHDOG_DEPS, 'watchdog', 'build', 'lib3' ),
#                      p.join( DIR_OF_WATCHDOG_DEPS, 'pathtools' ),
#                      p.join( DIR_OF_THIRD_PARTY, 'waitress' ) ]

#  sys_path.append( p.join( DIR_OF_THIRD_PARTY, 'jedi_deps', 'numpydoc' ) )
#  return sys_path

import os
import os.path
import fnmatch
import logging
import ycm_core
import re

BASE_FLAGS = [
    '-Wall',
    '-Wextra',
    '-pedantic',
    '-Wshadow',
    '-Wformat=2',
    '-Wfloat-equal',
    '-Wconversion',
    '-Wlogical-op',
    '-Wcast-qual',
    '-Wcast-align',
    '-std=c++17',
    '-x',
    'c++',
]

SOURCE_EXTENSIONS = [
    '.cpp',
    '.cxx',
    '.cc',
    '.c',
    '.m',
    '.mm',
]

SOURCE_DIRECTORIES = [
    'src',
    'lib',
]

HEADER_EXTENSIONS = [
    '.h',
    '.hxx',
    '.hpp',
    '.hh',
]

HEADER_DIRECTORIES = [
    'include',
]

BUILD_DIRECTORY = 'build';

FLAG_FILES = [
    'compile_flags.txt',
    '.clang_complete',
]

def IsHeaderFile(filename):
    extension = os.path.splitext(filename)[1]
    return extension in HEADER_EXTENSIONS

def FindNearest(path, target, build_folder=None):
    candidate = os.path.join(path, target)
    if(os.path.isfile(candidate) or os.path.isdir(candidate)):
        logging.info("Found nearest " + target + " at " + candidate)
        return candidate;

    parent = os.path.dirname(os.path.abspath(path));
    if(parent == path):
        raise RuntimeError("Could not find " + target);

    if(build_folder):
        candidate = os.path.join(parent, build_folder, target)
        if(os.path.isfile(candidate) or os.path.isdir(candidate)):
            logging.info("Found nearest " + target + " in build folder at " + candidate)
            return candidate;

    return FindNearest(parent, target, build_folder)

def CompilationDatabaseToFlags(database, filename):
    compilation_info = database.GetCompilationInfoForFile(filename)
    if compilation_info.compiler_flags_:
        return {
            'flags': compilation_info.compiler_flags_,
            'include_paths_relative_to_dir': compilation_info.compiler_working_dir_,
            'override_filename': filename,
        }
    return None

def GetCompilationInfoForFile(database, filename):
    flags = CompilationDatabaseToFlags(database, filename)
    if flags:
        return flags

    if IsHeaderFile(filename):
        basename = os.path.splitext(filename)[0]
        for extension in SOURCE_EXTENSIONS:
            # Get info from the source files by replacing the extension.
            replacement_file = basename + extension
            if os.path.exists(replacement_file):
                flags = CompilationDatabaseToFlags(database, replacement_file)
                if flags:
                    return flags
            # If that wasn't successful, try replacing possible header directory with possible source directories.
            for header_dir in HEADER_DIRECTORIES:
                for source_dir in SOURCE_DIRECTORIES:
                    src_file = replacement_file.replace(header_dir, source_dir)
                    if os.path.exists(src_file):
                        flags = CompilationDatabaseToFlags(database, src_file)
                        if flags:
                            return flags

    return None

def FlagsFromClangComplete(root):
    for filename in FLAG_FILES:
        try:
            clang_complete_path = FindNearest(root, filename)
            clang_complete_flags = open(clang_complete_path, 'r').read().splitlines()
            return {
                'flags': clang_complete_flags,
                'include_paths_relative_to_dir': os.path.dirname(clang_complete_path),
            }
        except Exception:
            pass
    return None

def FlagsFromInclude(root):
    try:
        include_path = FindNearest(root, 'include')
        flags = BASE_FLAGS
        for dirroot, dirnames, filenames in os.walk(include_path):
            for dir_path in dirnames:
                real_path = os.path.join(dirroot, dir_path)
                flags = flags + ["-I" + real_path]
        return { 'flags': flags }
    except Exception:
        pass

    return None

def FlagsFromCompilationDatabase(root, filename):
    try:
        # Last argument of next function is the name of the build folder for
        # out of source projects
        compilation_db_path = FindNearest(root, 'compile_commands.json', BUILD_DIRECTORY)
        compilation_db_dir = os.path.dirname(compilation_db_path)
        logging.info("Set compilation database directory to " + compilation_db_dir)
        compilation_db =  ycm_core.CompilationDatabase(compilation_db_dir)
        if not compilation_db:
            logging.info("Compilation database file found but unable to load")
            return None
        compilation_info = GetCompilationInfoForFile(compilation_db, filename)
        if not compilation_info:
            logging.info("No compilation info for " + filename + " in compilation database")
            return None
        return compilation_info
    except Exception:
        return None

def FlagsForCfamily(**kwargs):
    filename = kwargs['filename']
    root = os.path.realpath(filename);

    compilation_db_flags = FlagsFromCompilationDatabase(root, filename)
    if compilation_db_flags:
        return compilation_db_flags

    clang_flags = FlagsFromClangComplete(root)
    if clang_flags:
        return clang_flags

    include_flags = FlagsFromInclude(root)
    if include_flags:
        return include_flags

    return { 'flags': BASE_FLAGS, }

def Settings(**kwargs):
    language = kwargs[ 'language' ]
    if language == 'cfamily':
        return FlagsForCfamily(**kwargs)
    if language == 'python':
        # TODO
        return {}
    return {}
