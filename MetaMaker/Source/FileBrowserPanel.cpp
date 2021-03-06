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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FileBrowserPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FileBrowserPanel::FileBrowserPanel (const int& initialWidth, const int& initialHeight, const String& initialPath)
{
    //[Constructor_pre] You can add your own custom stuff here..
    wildCardFileFilter = std::make_unique<WildcardFileFilter> (Defines::fileFilterAllowForAudioFiles, Defines::fileFilterDirPatterns, Defines::fileFilterDescription);
    
    // Handles the file restrictions and permissions of the File Browser
    fileBrowserTypeFlags =  FileBrowserComponent::FileChooserFlags::openMode +
    FileBrowserComponent::FileChooserFlags::canSelectFiles +
    FileBrowserComponent::FileChooserFlags::canSelectMultipleItems;

    // Make the File Browser
    fileBrowser = std::make_unique<FileBrowserComponent> (fileBrowserTypeFlags, File (initialPath), wildCardFileFilter.get(), nullptr);
    
    fileBrowser->setSize(initialWidth, initialHeight);
    
    addAndMakeVisible(*fileBrowser);
    //[/Constructor_pre]


    //[UserPreSize]

    //[/UserPreSize]

    setSize (initialWidth, initialHeight);


    //[Constructor] You can add your own custom stuff here..
    fileBrowser -> refresh();
    //[/Constructor]
}

FileBrowserPanel::~FileBrowserPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //delete fileBrowser;
    //[/Destructor_pre]

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}


void FileBrowserPanel::labelTextChanged (Label *labelThatHasChanged)
{
    fileBrowser -> deselectAllFiles();
    fileBrowser -> setRoot(labelThatHasChanged -> getText());
}


//==============================================================================
void FileBrowserPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (backgroundColour);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FileBrowserPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FileBrowserPanel" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

