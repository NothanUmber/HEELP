/*
 * This file is part of HEELP.
 * Copyright (c) 2016 Uwyn SPRL.  http://www.uwyn.com
 *
 * HEELP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HEELP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "AudioSlaveProcess.h"

#include "AudioProcessMessageTypes.h"
#include "AudioProcessMessageUtils.h"
#include "../Utils.h"

using namespace heelp;

AudioSlaveProcess::AudioSlaveProcess()
{
}
    
void AudioSlaveProcess::handleMessageFromMaster(const MemoryBlock& mb)
{
    ValueTree msg(memoryBlockToValueTree(mb));
    String type = msg.getType().toString();
    if (type == AudioProcessMessageTypes::AUDIODEVICEMANAGER_STATEXML)
    {
        String stateXml = msg.getProperty(AudioProcessMessageProperties::STATE).toString();
        // TODO
    }
}

void AudioSlaveProcess::handleConnectionMade()
{
}

void AudioSlaveProcess::handleConnectionLost()
{
    JUCEApplication::quit();
}
