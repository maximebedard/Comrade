# Tell SCons to create our build files in the 'build' directory
VariantDir('bin', 'src', duplicate=0)

# Set our source files
source_files = Glob('bin/*.cpp', 'bin/*.h')

# Set our required libraries
libraries = []
library_paths = ''

env = Environment()
env.Replace(CXX='clang++')

# Set our g++ compiler flags
env.Append( CPPFLAGS=['-std=c++11', '-pthread', '-Wall', '-g'] )

# Tell SCons the program to build
env.Program('bin/comrade', source_files, LIBS = libraries, LIBPATH = library_paths)
