//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#include "clients.h"

ClientInfo clients[] = {
	{0,0,0, false, false, 0, 0, 0, 0, 0, 0},
//  version XTEA  CRC         gameState      -        XTEA key               recv                   send             connect
	{8,4,0, true, true, (uint32_t*)0x788370, 4, (uint32_t*)0x784D0C, (uint32_t*)0x5AB5D4, (uint32_t*)0x5AB600, (uint32_t*)0x5AB5B4}
};

const ClientInfo& getClientInfo(const ClientVersion& version)
{
	for(unsigned int i = 1; i < sizeof(clients)/sizeof(ClientInfo); ++i){
		if(clients[i].major == version.major &&
			clients[i].minor == version.minor &&
			clients[i].revision == version.revision){
			return clients[i];
		}
	}
	return clients[0];
}
