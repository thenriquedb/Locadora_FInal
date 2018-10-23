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
	${OBJECTDIR}/alocacao.o \
	${OBJECTDIR}/cadastros.o \
	${OBJECTDIR}/filtrosRel_Categorias.o \
	${OBJECTDIR}/filtrosRel_Clientes.o \
	${OBJECTDIR}/filtrosRel_Filmes.o \
	${OBJECTDIR}/filtrosRel_Fornecedores.o \
	${OBJECTDIR}/filtrosRel_Funcionarios.o \
	${OBJECTDIR}/gestaoCategoria.o \
	${OBJECTDIR}/gestaoCliente.o \
	${OBJECTDIR}/gestaoFIlme.o \
	${OBJECTDIR}/gestaoFornecedores.o \
	${OBJECTDIR}/gestaoFuncionario.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/menus.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/locadora ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/alocacao.o: alocacao.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/alocacao.o alocacao.c

${OBJECTDIR}/cadastros.o: cadastros.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cadastros.o cadastros.c

${OBJECTDIR}/filtrosRel_Categorias.o: filtrosRel_Categorias.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRel_Categorias.o filtrosRel_Categorias.c

${OBJECTDIR}/filtrosRel_Clientes.o: filtrosRel_Clientes.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRel_Clientes.o filtrosRel_Clientes.c

${OBJECTDIR}/filtrosRel_Filmes.o: filtrosRel_Filmes.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRel_Filmes.o filtrosRel_Filmes.c

${OBJECTDIR}/filtrosRel_Fornecedores.o: filtrosRel_Fornecedores.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRel_Fornecedores.o filtrosRel_Fornecedores.c

${OBJECTDIR}/filtrosRel_Funcionarios.o: filtrosRel_Funcionarios.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filtrosRel_Funcionarios.o filtrosRel_Funcionarios.c

${OBJECTDIR}/gestaoCategoria.o: gestaoCategoria.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestaoCategoria.o gestaoCategoria.c

${OBJECTDIR}/gestaoCliente.o: gestaoCliente.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestaoCliente.o gestaoCliente.c

${OBJECTDIR}/gestaoFIlme.o: gestaoFIlme.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestaoFIlme.o gestaoFIlme.c

${OBJECTDIR}/gestaoFornecedores.o: gestaoFornecedores.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestaoFornecedores.o gestaoFornecedores.c

${OBJECTDIR}/gestaoFuncionario.o: gestaoFuncionario.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestaoFuncionario.o gestaoFuncionario.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/menus.o: menus.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/menus.o menus.c

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
