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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GUI.o \
	${OBJECTDIR}/administracao.o \
	${OBJECTDIR}/alocacao.o \
	${OBJECTDIR}/cadastros.o \
	${OBJECTDIR}/edicaoDados.o \
	${OBJECTDIR}/excluirDados.o \
	${OBJECTDIR}/fileExportBIN.o \
	${OBJECTDIR}/fileExportTXT.o \
	${OBJECTDIR}/fileImportBIN.o \
	${OBJECTDIR}/fileImportTXT.o \
	${OBJECTDIR}/fileXML.o \
	${OBJECTDIR}/filtrosRelatorios.o \
	${OBJECTDIR}/financas.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menus.o \
	${OBJECTDIR}/teste.o \
	${OBJECTDIR}/verificacaoDeDados.o


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
LDLIBSOPTIONS=-lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/GUI.o: GUI.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GUI.o GUI.c

${OBJECTDIR}/administracao.o: administracao.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/administracao.o administracao.c

${OBJECTDIR}/alocacao.o: alocacao.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/alocacao.o alocacao.c

${OBJECTDIR}/cadastros.o: cadastros.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cadastros.o cadastros.c

${OBJECTDIR}/edicaoDados.o: edicaoDados.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/edicaoDados.o edicaoDados.c

${OBJECTDIR}/excluirDados.o: excluirDados.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/excluirDados.o excluirDados.c

${OBJECTDIR}/fileExportBIN.o: fileExportBIN.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fileExportBIN.o fileExportBIN.c

${OBJECTDIR}/fileExportTXT.o: fileExportTXT.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fileExportTXT.o fileExportTXT.c

${OBJECTDIR}/fileImportBIN.o: fileImportBIN.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fileImportBIN.o fileImportBIN.c

${OBJECTDIR}/fileImportTXT.o: fileImportTXT.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fileImportTXT.o fileImportTXT.c

${OBJECTDIR}/fileXML.o: fileXML.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/fileXML.o fileXML.c

${OBJECTDIR}/filtrosRelatorios.o: filtrosRelatorios.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRelatorios.o filtrosRelatorios.c

${OBJECTDIR}/financas.o: financas.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/financas.o financas.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menus.o: menus.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menus.o menus.c

${OBJECTDIR}/teste.o: teste.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/teste.o teste.c

${OBJECTDIR}/verificacaoDeDados.o: verificacaoDeDados.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/verificacaoDeDados.o verificacaoDeDados.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
