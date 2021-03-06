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
class FileBrowserPanel  : public Component,
                          public Label::Listener
{
public:
    //==============================================================================
    //FileBrowserPanel ();
    FileBrowserPanel (const int& initialWidth, const int& initialHeight, const String& initialPath);
    ~FileBrowserPanel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    File getCurrentFile() const noexcept                            {   return this -> fileBrowser -> getHighlightedFile();     }
    
    //Overload for case when multiple files are selected
    File getCurrentFile (int& index) const noexcept                 {   return this -> fileBrowser -> getSelectedFile (index);  }
    
    
    const int getNumSelectedFiles () const noexcept                 {   return this -> fileBrowser -> getNumSelectedFiles();        }

    FileBrowserComponent* getFileBrowser () const noexcept          {   return this -> fileBrowser.get();  }

    const File getRoot () const noexcept                            {   return this -> fileBrowser -> getRoot ();  }
    void setRoot (const File& newRootDirectory )                    {   this -> fileBrowser -> setRoot (newRootDirectory);   }
    
    const String getFullPath () const noexcept                      {   return this -> fileBrowser -> getRoot ().getFullPathName ();  }

    const void refreshFileBrowser () const noexcept                 {   this -> fileBrowser -> refresh ();}
    
    const String getCurrentFileName () const noexcept               {   return this -> fileBrowser -> getHighlightedFile ().getFileName ();   }
    
    const bool isCurrentlySelectedFileDirectory () const noexcept   {   return this -> getCurrentFile ().isDirectory ();  }
    
    const int getNumSelectedFiles ()                                {   return this -> fileBrowser -> getNumSelectedFiles();   }
    
    
    void labelTextChanged (Label *labelThatHasChanged) override;
    
    
    
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    std::unique_ptr<WildcardFileFilter> wildCardFileFilter; // Makes sure that only Wav files are displayed
    
    int fileBrowserTypeFlags;

    File initialFilePath;

    std::unique_ptr<FileBrowserComponent> fileBrowser;
    
    Colour backgroundColour;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileBrowserPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

