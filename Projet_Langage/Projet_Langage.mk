##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Projet_Langage
ConfigurationName      :=Debug
WorkspacePath          :=/Users/Guillaume/Documents/ESILV/Annee_3/CodeLiteProjects
ProjectPath            :=/Users/Guillaume/Documents/ESILV/Annee_3/CodeLiteProjects/Projet_Langage
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Guillaume Stasinski
Date                   :=14/12/2017
CodeLitePath           :="/Users/Guillaume/Library/Application Support/codelite"
LinkerName             :=/Applications/Xcode.app/Contents/Developer/usr/bin/g++
SharedObjectLinkerName :=/Applications/Xcode.app/Contents/Developer/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Projet_Langage.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /Applications/Xcode.app/Contents/Developer/usr/bin/g++
CC       := /Applications/Xcode.app/Contents/Developer/usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/private/var/folders/3z/ycpnf7z52f3d2v44gf7jyl600000gn/T/AppTranslocation/37129A28-B5A5-42D5-A297-220E832763B5/d/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/table.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c 
	$(CC) $(SourceSwitch) "/Users/Guillaume/Documents/ESILV/Annee_3/CodeLiteProjects/Projet_Langage/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/table.c$(ObjectSuffix): table.c 
	$(CC) $(SourceSwitch) "/Users/Guillaume/Documents/ESILV/Annee_3/CodeLiteProjects/Projet_Langage/table.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/table.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/table.c$(PreprocessSuffix): table.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/table.c$(PreprocessSuffix) table.c

##
## Clean
##
clean:
	$(RM) -r ./Debug/


