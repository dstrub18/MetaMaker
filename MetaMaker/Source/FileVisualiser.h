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
        Logger::writeToLog(file.getFileName());
    }

    void paint (Graphics& g) override
    {
        Rectangle<int> thumbnailBounds (0, 0, getWidth(), getHeight());
        
        
        if (thumbnail.getNumChannels() == 0)
        {
            paintIfNoFileLoaded (g, thumbnailBounds);
        }
        
        else
        {
            paintIfFileLoaded (g, thumbnailBounds);
        }
        
    }
    
    void paintIfNoFileLoaded (Graphics& g, Rectangle<int> thumbnailBounds)
    {
        g.setColour (Colours::darkgrey);
        g.fillRect(thumbnailBounds);
        g.setColour (Colours::white);
        g.drawFittedText ("No File Loaded", thumbnailBounds, Justification::centred, 1);
    }
    
    void paintIfFileLoaded (Graphics& g, Rectangle<int> thumbnailBounds)
    {
        g.setColour (Colours::white);
        g.fillRect(thumbnailBounds);
        g.setColour (Colours::green);
        g.drawFittedText ("File Loaded", thumbnailBounds, Justification::centred, 1);
//        thumbnail.drawChannels (g,
//                                thumbnailBounds,
//                                0.0,                                    // start time
//                                thumbnail.getTotalLength(),             // end time
//                                1.0f);                                  // vertical zoom
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
    
    void setSource (File file)
    {
        this -> thumbnail.setSource(new FileInputSource(file));
    }

private:
    
    void thumbnailChanged()
    {
        repaint();
    }
    
    
    
    AudioThumbnail thumbnail;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FileVisualiser)
};
