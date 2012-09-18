/*
 * Mp3Decoder.h
 *
 *  Created on: Sep 6, 2012
 *      Author: craig
 */

#ifndef MP3DECODER_H_
#define MP3DECODER_H_

#include<string>
#include<stdint.h>

#include<stdio.h>

extern"C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
}

#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"
#define SDL_AUDIO_BUFFER_SIZE 1024


class Mp3Decoder {
public:
	Mp3Decoder(std::string fileName);
	virtual ~Mp3Decoder();

	int frameSize();
	void getAudioFrame(uint8_t* data);
	int openMP3(std::string filename);

private :
	AVFormatContext *pFormatCtx;
	int i;
	int videoStream;
	int audioStream;

	AVCodecContext  *pCodecCtx;
	AVCodec         *pCodec;
	AVFrame         *pFrame;
	AVPacket        packet;
	int             frameFinished;
	float           aspect_ratio;

	AVCodecContext  *aCodecCtx;
	AVCodec         *aCodec;

	SDL_Overlay     *bmp;
	SDL_Surface     *screen;
	SDL_Rect        rect;
	SDL_Event       event;
	SDL_AudioSpec   wanted_spec, spec;
};

#endif /* MP3DECODER_H_ */
