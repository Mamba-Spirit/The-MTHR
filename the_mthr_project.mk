##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=the_mthr_project
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/axel/Documents/Module5_Etudiant
ProjectPath            :=/home/axel/Documents/Module5_Etudiant/the_mthr_project
IntermediateDirectory  :=../build-$(ConfigurationName)/the_mthr_project
OutDir                 :=../build-$(ConfigurationName)/the_mthr_project
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=04/03/23
CodeLitePath           :=/home/axel/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)i2c 
ArLibs                 :=  "i2c" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/the_mthr_project/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/the_mthr_project/App.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/the_mthr_project/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/the_mthr_project"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/the_mthr_project"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/the_mthr_project/.d:
	@mkdir -p "../build-$(ConfigurationName)/the_mthr_project"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/the_mthr_project/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/the_mthr_project/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/axel/Documents/Module5_Etudiant/the_mthr_project/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/the_mthr_project/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/the_mthr_project/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/the_mthr_project/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/the_mthr_project/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/the_mthr_project/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(ObjectSuffix): SHTC3.cpp ../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/axel/Documents/Module5_Etudiant/the_mthr_project/SHTC3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SHTC3.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(DependSuffix): SHTC3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(DependSuffix) -MM SHTC3.cpp

../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(PreprocessSuffix): SHTC3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/the_mthr_project/SHTC3.cpp$(PreprocessSuffix) SHTC3.cpp

../build-$(ConfigurationName)/the_mthr_project/App.cpp$(ObjectSuffix): App.cpp ../build-$(ConfigurationName)/the_mthr_project/App.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/axel/Documents/Module5_Etudiant/the_mthr_project/App.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/App.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/the_mthr_project/App.cpp$(DependSuffix): App.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/the_mthr_project/App.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/the_mthr_project/App.cpp$(DependSuffix) -MM App.cpp

../build-$(ConfigurationName)/the_mthr_project/App.cpp$(PreprocessSuffix): App.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/the_mthr_project/App.cpp$(PreprocessSuffix) App.cpp

../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(ObjectSuffix): AccesI2C.cpp ../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/axel/Documents/Module5_Etudiant/the_mthr_project/AccesI2C.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AccesI2C.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(DependSuffix): AccesI2C.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(DependSuffix) -MM AccesI2C.cpp

../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(PreprocessSuffix): AccesI2C.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/the_mthr_project/AccesI2C.cpp$(PreprocessSuffix) AccesI2C.cpp


-include ../build-$(ConfigurationName)/the_mthr_project//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


