/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
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
    FileBrowserPanel (const int panelWidth, const int panelHeight, String initialPath);
    
    ~FileBrowserPanel();
    

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    inline File getCurrentFile(){  return this -> fileBrowser -> getHighlightedFile();   };
    
    inline FileBrowserComponent* getFileBrowser () { return this -> fileBrowser ;  };
    
    
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    //void inline setFilePath(String& filePath) {this->fileBrowser->;};
    

private:

    //[UserVariables]   -- You can add your own custom variables in this section.
    
    std::unique_ptr<WildcardFileFilter> wildCardFileFilter; // Makes sure that only Wav files are displayed
    int fileBrowserTypeFlags;
    
    File initialFilePath;
    
    FileBrowserComponent* fileBrowser;
    
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileBrowserPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

