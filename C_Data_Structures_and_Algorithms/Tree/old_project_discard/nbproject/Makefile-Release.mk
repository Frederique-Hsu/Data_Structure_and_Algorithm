#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Tree/Main.o \
	${OBJECTDIR}/Tree/Test.o \
	${OBJECTDIR}/Tree/Tree_Structure/Stack.o \
	${OBJECTDIR}/Tree/Tree_Structure/Test_Tree.o \
	${OBJECTDIR}/Tree/Tree_Structure/Tree.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tree

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tree: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tree ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Tree/Main.o: Tree/Main.c 
	${MKDIR} -p ${OBJECTDIR}/Tree
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree/Main.o Tree/Main.c

${OBJECTDIR}/Tree/Test.o: Tree/Test.c 
	${MKDIR} -p ${OBJECTDIR}/Tree
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree/Test.o Tree/Test.c

${OBJECTDIR}/Tree/Tree_Structure/Stack.o: Tree/Tree_Structure/Stack.c 
	${MKDIR} -p ${OBJECTDIR}/Tree/Tree_Structure
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree/Tree_Structure/Stack.o Tree/Tree_Structure/Stack.c

${OBJECTDIR}/Tree/Tree_Structure/Test_Tree.o: Tree/Tree_Structure/Test_Tree.c 
	${MKDIR} -p ${OBJECTDIR}/Tree/Tree_Structure
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree/Tree_Structure/Test_Tree.o Tree/Tree_Structure/Test_Tree.c

${OBJECTDIR}/Tree/Tree_Structure/Tree.o: Tree/Tree_Structure/Tree.c 
	${MKDIR} -p ${OBJECTDIR}/Tree/Tree_Structure
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree/Tree_Structure/Tree.o Tree/Tree_Structure/Tree.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tree

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
