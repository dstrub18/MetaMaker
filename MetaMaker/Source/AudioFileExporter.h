/*
  ==============================================================================

    AudioFileExporter.h
    Created: 24 Jul 2020 4:21:19pm
    Author:  Daniel Strübig

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class AudioFileExporter
{
    AudioFileExporter ();
    ~AudioFileExporter ();
    
    
public:
    
    void exportFullAudioFile (const String& outputPath);
    
    void exportAudioFileSection (const String& outputPath, float rectangleWidth);
    
    void resetReaders ();
    
    void setFileToExport (const File& file) noexcept    {    fileToExport = file;      }
    
private:
    
    File fileToExport;
    
    std::unique_ptr<WavAudioFormat> wavAudioFormat;
    AudioFormatManager audioFormatManager;
    AudioFormatReader* reader;
    AudioSubsectionReader* subsectionReader;
    
};
