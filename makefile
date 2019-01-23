#
# Makefile for StarWars game
#

# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CC          = g++

# The Target Binary Program
TARGET      = StarWars

# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      = src
INCDIR      = inc
OBJDIR      = obj
TARGETDIR   = bin
RESDIR      = res
SRCEXT      = cpp
DEPEXT      = d
OBJEXT      = o

# Flags, Libraries and Includes
# The CFLAGS variable sets compile flags for g++:
# -g				Compile with debug information
# -Wall				Give verbose compiler warnings		
# -std=c++0x		Use the C++0x standard definition language
CFLAGS      = -g -Wall -std=c++0x

# The LDFLAGS variable sets flags for linker
LFLAGS = 

# Libraries and Includes
# -I$(INCDIR)		Tells compiler where to look for include files 
LIB         = 
INC         = -I$(INCDIR)
INCDEP      = -I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------

# Source files are detected via shell find command
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

# Default Make
all: resources $(TARGET)

# Remake (Cleaner + Make)
remake: cleaner all

# Copy Resources from Resources Directory to Target Directory
resources: directories
	#@cp $(RESDIR)/* $(TARGETDIR)/

# Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(OBJDIR)

# Clean only Objects
clean:
	@$(RM) -rf $(OBJDIR)

# Full Clean, Objects and Binaries
cleaner: clean
	@$(RM) -rf $(TARGETDIR)

# Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

# Compile project and automatically generate a dependency file for each 
# object. This means that modification of headers and inline files will trigger 
# recompilation of files which are dependent.
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(OBJDIR)/$*.$(DEPEXT)
	@cp -f $(OBJDIR)/$*.$(DEPEXT) $(OBJDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.$(OBJEXT):|' < $(OBJDIR)/$*.$(DEPEXT).tmp > $(OBJDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(OBJDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(OBJDIR)/$*.$(DEPEXT)
	@rm -f $(OBJDIR)/$*.$(DEPEXT).tmp

# Non-File Targets
.PHONY: all remake clean cleaner resources

# Sources
# https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory
# http://scottmcpeak.com/autodepend/autodepend.html
