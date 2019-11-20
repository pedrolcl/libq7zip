/**************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <https://www.gnu.org/licenses/>.
**
**************************************************************************/

#ifndef Q7Z_GUID_H
#define Q7Z_GUID_H

#include <Common/MyInitGuid.h>

#ifdef __cplusplus
#define DEFINE_7Z_GUID(name, b4, b5, b6) extern "C" const GUID IID_ ## name = { 0x23170F69, \
    0x40C1, 0x278A, { 0x00, 0x00, 0x00,  b4,  b5,  b6, 0x00, 0x00 } }
#else
#define DEFINE_7Z_GUID(name, b4, b5, b6) extern const GUID IID_ ## name = { 0x23170F69, \
    0x40C1, 0x278A, { 0x00, 0x00, 0x00,  b4,  b5,  b6, 0x00, 0x00 } }
#endif

DEFINE_7Z_GUID(IInArchiveGetStream,             0x06, 0x00, 0x40);
DEFINE_7Z_GUID(IInArchive,                      0x06, 0x00, 0x60);

DEFINE_7Z_GUID(IOutStream,                      0x03, 0x00, 0x04);
DEFINE_7Z_GUID(IOutStreamFlush,                 0x03, 0x00, 0x07);
DEFINE_7Z_GUID(IOutArchive,                     0x06, 0x00, 0xA0);

DEFINE_7Z_GUID(IInStream,                       0x03, 0x00, 0x03);

DEFINE_7Z_GUID(ISetProperties,                  0x06, 0x00, 0x03);

DEFINE_7Z_GUID(ISequentialInStream,             0x03, 0x00, 0x01);
DEFINE_7Z_GUID(ISequentialOutStream,            0x03, 0x00, 0x02);

DEFINE_7Z_GUID(IStreamGetSize,                  0x03, 0x00, 0x06);
DEFINE_7Z_GUID(IStreamGetProps,                 0x03, 0x00, 0x08);
DEFINE_7Z_GUID(IStreamGetProps2,                0x03, 0x00, 0x09);

DEFINE_7Z_GUID(IArchiveKeepModeForNextOpen,     0x06, 0x00, 0x04);
DEFINE_7Z_GUID(IArchiveAllowTail,               0x06, 0x00, 0x05);
DEFINE_7Z_GUID(IArchiveOpenCallback,            0x06, 0x00, 0x10);
DEFINE_7Z_GUID(IArchiveExtractCallback,         0x06, 0x00, 0x20);
DEFINE_7Z_GUID(IArchiveOpenVolumeCallback,      0x06, 0x00, 0x30);
DEFINE_7Z_GUID(IArchiveOpenSetSubArchiveName,   0x06, 0x00, 0x50);
DEFINE_7Z_GUID(IArchiveOpenSeq,                 0x06, 0x00, 0x61);
DEFINE_7Z_GUID(IArchiveGetRawProps,             0x06, 0x00, 0x70);
DEFINE_7Z_GUID(IArchiveGetRootProps,            0x06, 0x00, 0x71);
DEFINE_7Z_GUID(IArchiveUpdateCallback,          0x06, 0x00, 0x80);
DEFINE_7Z_GUID(IArchiveUpdateCallback2,         0x06, 0x00, 0x82);

DEFINE_7Z_GUID(ICompressProgressInfo,             0x04, 0x00, 0x04);
DEFINE_7Z_GUID(ICompressCoder,                    0x04, 0x00, 0x05);
DEFINE_7Z_GUID(ICompressSetCoderProperties,       0x04, 0x00, 0x20);
DEFINE_7Z_GUID(ICompressSetDecoderProperties2,    0x04, 0x00, 0x22);
DEFINE_7Z_GUID(ICompressWriteCoderProperties,     0x04, 0x00, 0x23);
DEFINE_7Z_GUID(ICompressGetInStreamProcessedSize, 0x04, 0x00, 0x24);
DEFINE_7Z_GUID(ICompressSetCoderMt,               0x04, 0x00, 0x25);
DEFINE_7Z_GUID(ICompressSetOutStream,             0x04, 0x00, 0x32);
DEFINE_7Z_GUID(ICompressSetInStream,              0x04, 0x00, 0x31);
DEFINE_7Z_GUID(ICompressSetOutStreamSize,         0x04, 0x00, 0x34);
DEFINE_7Z_GUID(ICompressSetBufSize,               0x04, 0x00, 0x35);
DEFINE_7Z_GUID(ICompressGetSubStreamSize,         0x04, 0x00, 0x30);
DEFINE_7Z_GUID(ICryptoResetInitVector,            0x04, 0x00, 0x8C);
DEFINE_7Z_GUID(ICryptoSetPassword,                0x04, 0x00, 0x90);

DEFINE_7Z_GUID(ICryptoGetTextPassword,            0x05, 0x00, 0x10);
DEFINE_7Z_GUID(ICryptoGetTextPassword2,           0x05, 0x00, 0x11);

#undef DEFINE_7Z_GUID

#endif // Q7Z_GUID_H
