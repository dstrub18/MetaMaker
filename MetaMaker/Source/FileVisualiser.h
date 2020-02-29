/*
  ==============================================================================

    FileVisualiser.h
    Created: 29 Feb 2020 7:07:19pm
    Author:  Strue Audio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FileVisualiser    : public Component,
                          private ChangeListener
{
public:
    FileVisualiser(int sourceSamplesPerThumbnailSample,
                   AudioFormatManager& formatManager,
                   AudioThumbnailCache& cache)
    : thumbnail (sourceSamplesPerThumbnailSample, formatManager, cache)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }
    ~FileVisualiser()
    {
    }
    
    
    void setFile (const File& file)
    {
        thumbnail.setSource (new FileInputSource (file));
    }

    void paint (Graphics& g) override
    {
        if (thumbnail.getNumChannels() == 0)
            paintIfNoFileLoaded (g);
        else
            paintIfFileLoaded (g);
    }
    
    void paintIfNoFileLoaded (Graphics& g)
    {
        g.fillAll (Colours::white);
        g.setColour (Colours::darkgrey);
        g.drawFittedText ("No File Loaded", getLocalBounds(), Justification::centred, 1);
    }
    
    void paintIfFileLoaded (Graphics& g)
    {
        g.fillAll(Colours::white);
        
        g.setColour (Colours::red);
        thumbnail.drawChannels (g, getLocalBounds(), 0.0, thumbnail.getTotalLength(), 1.0f);
    }
    
    void changeListenerCallback (ChangeBroadcaster* source) override
    {
        if (source == &thumbnail)
            thumbnailChanged();
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    
    void thumbnailChanged()
    {
        repaint();
    }
    
    AudioThumbnail thumbnail;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileVisualiser)
};
