//
//  FingerPosition.cpp
//  leapmidi
//
//  Created by Mischa Spiegelmock on 12/13/12.
//  Copyright (c) 2012 int80. All rights reserved.
//

#include "FingerPosition.h"

namespace leapmidi {

const midi_control_index FingerPosition::controlIndex() {
    // how many controls do we have per hand?
    unsigned long handControlCount = FINGER_1_HAND_2_X - FINGER_1_HAND_1_X;
    unsigned long _controlIndex = controlIndexBase() + fingerIndex() * 3; // gives us finger control index
    _controlIndex += (handIndex() - 1) * handControlCount; // offset by hand count

    return (midi_control_index)_controlIndex;
}

const midi_note_index FingerPosition::noteIndexOn() {
    // how many notes do we have per hand?
    unsigned long handNoteCount = FINGER_1_HAND_2_X_ON - FINGER_1_HAND_1_X_ON;
    unsigned long _noteIndex = noteIndexBase() + 2 * (fingerIndex() - 1); // gives us finger note index
    _noteIndex += (handIndex() - 1) * handNoteCount; // offset by hand count
    
    return (midi_note_index)_noteIndex;
}

const midi_note_index FingerPosition::noteIndexOff() {
    return (midi_note_index)(noteIndexOn() + 1); // always goes _on, _off
}

}
