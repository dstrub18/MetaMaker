/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Defines.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FileBrowserPanel  : public Component
{
public:
    //==============================================================================
    //FileBrowserPanel ();
    FileBrowserPanel (const int& initialWidth, const int& initialHeight, const String& initialPath);
    ~FileBrowserPanel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    File getCurrentFile()                           {   return this -> fileBrowser -> getHighlightedFile();   }

    FileBrowserComponent* getFileBrowser ()         {   return this -> fileBrowser;  }

    const File getRoot ()                           {   return this -> fileBrowser -> getRoot();  }
    void setRoot (const File& newRootDirectory )    {   this -> fileBrowser -> setRoot(newRootDirectory);   }
    
    const String getFullPath ()                     {   return this -> fileBrowser -> getRoot().getFullPathName();  }

    const void refreshFileBrowser ()                {   this -> fileBrowser -> refresh();}
    
    const String getCurrentFileName ()              {   return this -> fileBrowser -> getHighlightedFile().getFileName();   }
    
    const bool isCurrentlySelectedFileDirectory()   {   return this -> getCurrentFile().isDirectory();  }
    
    
    
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    std::unique_ptr<WildcardFileFilter> wildCardFileFilter; // Makes sure that only Wav files are displayed
    int fileBrowserTypeFlags;

    File initialFilePath;

    FileBrowserComponent* fileBrowser;
    
    Colour backgroundColour;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileBrowserPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

