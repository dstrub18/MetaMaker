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
    
    static const int initialFileBrowserWidth = 200; // Isn't that handled automatically when using a flexbox?
    static const int initialEditPanelWidth = 400;
    static const int initialFileInfoWidth = 200;
    
    static const int mainWindowTopYCoordinate = 0;
    
    
    static const Colour mainWindowBackgroundColour = Colours::grey; //  Unnecessary?
    static const Colour fileBrowserBackgroundColour = Colours::blanchedalmond;
    static const Colour editPanelBackgroundColour = Colours::red;
    static const Colour fileInfoPanelBackgroundColour = Colours::aliceblue;
    
    
}


namespace Defines {
    // Definitions of non-GUI-related variables that make the code more verbose and accessible.
    
    
    static const auto noNotification = juce::NotificationType::dontSendNotification;
    
    static const bool doNotreturnActiveEditorContents = false;
    static const bool returnActiveEditorContents = true;
    
    
}
