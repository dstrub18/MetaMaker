/*
  ==============================================================================

    GUIDefines.h
    Created: 2 Sep 2019 10:55:01am
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

namespace GUIDefines {
    // Definitions of GUI-related variables that make the code more verbose and accessible.
    
    static const int marginBetweenComponents = 10;
    static const int buttonHeight = 30;
    static const int buttonAreaWidth = 150;
    
    static const int initialFileBrowserWidth = 300; // Isn't that handled automatically when using a flexbox?
    static const int initialEditPanelWidth = 200;
    static const int initialFileInfoWidth = 300;
    
    static const int universalHeight = 600;
    
    static const int mainWindowTopYCoordinate = 0;
    
    static const String metadataButtonText = "Write Metadata";
    
    static const Colour mainWindowBackgroundColour = Colours::grey; //  Unnecessary?
    static const Colour fileBrowserBackgroundColour = Colours::blanchedalmond;
    static const Colour editPanelBackgroundColour = Colours::green;
    static const Colour fileInfoPanelBackgroundColour = Colours::aliceblue;
    
    static const unsigned int labelWidth = 150;
    static const unsigned int labelHeight = 24;
 
    
    
    
}



namespace Defines {
    // Definitions of non-GUI-related variables that make the code more verbose and accessible.
    
    
    static const auto noNotification = juce::NotificationType::dontSendNotification;
    
    static const bool doNotreturnActiveEditorContents = false;
    static const bool returnActiveEditorContents = true;
    
    static const StringPairArray emptyMetaDataFields  = StringPairArray ();
 
    // Keys for accessing the metadata
    static const String descriptionKey  = "bwav description";
    static const String originatorKey  = "bwav originator";
    static const String originationDateKey = "bwav origination date";
    
    // Label helpers and dimensions
    static const bool ON_SINGLE_CLICK_EDITABLE = false;
    static const bool ON_DOUBLE_CLICK_EDITABLE = true;
    static const bool DISCARD_CHANGES_ON_LOSS = false;
    
    
    
}
