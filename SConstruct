# Tell SCons to create our build files in the 'build' directory
VariantDir('bin', 'src', duplicate=0)

# Set our source files
source_files = Glob('bin/*.cpp', 'bin/*.hpp')

# Set our required libraries
libraries = ['libSDL2',
             'libboost_python',
             'libBulletMultiThreaded',
             'libBulletSoftBody',
             'libBulletDynamics',
             'libBulletCollision',
             'libLinearMath']

library_paths = '/usr/local/lib'
cpp_paths = '/usr/local/include/SDL2:vendor/cereal/include:/usr/local/include/bullet'

env = Environment()
env.Replace(CXX='clang++')

# Set our g++ compiler flags
env.Append( CPPFLAGS=['-std=c++11', '-Wall', '-g'] )

# Tell SCons the program to build
env.Program('bin/comrade', source_files,CPPPATH = cpp_paths, LIBS = libraries, LIBPATH = library_paths)
