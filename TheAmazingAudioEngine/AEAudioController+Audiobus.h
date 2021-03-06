//
//  AEAudioController+Audiobus.h
//  TheAmazingAudioEngine
//
//  Created by Michael Tyson on 06/05/2012.
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#ifdef __cplusplus
extern "C" {
#endif

#import <Foundation/Foundation.h>
#import "AEAudioController.h"
#import <AudioToolbox/AudioToolbox.h>

@class ABReceiverPort;
@class ABAudioSenderPort;
@class ABAudioFilterPort;

@interface AEAudioController (AudiobusAdditions)

/*!
 * Set an Audiobus sender port to send audio from a particular channel
 *
 *  When assigned to a channel and connected via Audiobus, audio for the given channel
 *  will be sent out the Audiobus sender port.
 *
 * @param senderPort The Audiobus sender port, or nil to remove the port
 * @param channel    Channel for the sender port
 */
- (void)setAudiobusSenderPort:(ABAudioSenderPort*)senderPort forChannel:(id<AEAudioPlayable>)channel;

/*!
 * Set an Audiobus sender port to send audio from a particular channel group
 *
 *  When assigned to a channel and connected via Audiobus, audio for the given group
 *  will be sent out the Audiobus sender port.
 *
 * @param senderPort The Audiobus sender port, or nil to remove the port
 * @param channelGroup Channel group for the sender port
 */
- (void)setAudiobusSenderPort:(ABAudioSenderPort*)senderPort forChannelGroup:(AEChannelGroupRef)channelGroup;

/*!
 * Audiobus receiver port
 *
 *  Set this property to an Audiobus receiver port to receive audio
 *  from this port instead of the system audio input.
 */
@property (nonatomic, retain) ABReceiverPort *audiobusReceiverPort;

/*!
 * Audiobus filter port
 *
 *  Set this property to an Audiobus filter port to let TAAE correctly update the
 *  number of input channels when connected.
 */
@property (nonatomic, retain) ABAudioFilterPort *audiobusFilterPort __deprecated_msg("No longer in use");

/*!
 * Audiobus sender port
 *
 *  Deprecated: use ABAudioSenderPort's audio unit initializer (using
 *  AEAudioController's [audioUnit](@ref AEAudioController::audioUnit) property.
 *
 *  This method has been deprecated, as it doesn't support synchronization
 *  and latency compensation.
 */
@property (nonatomic, retain) ABAudioSenderPort *audiobusSenderPort __deprecated_msg("use ABAudioSenderPort's audio unit initializer instead");

@end

#ifdef __cplusplus
}
#endif
