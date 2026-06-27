#ifndef BLADETYPES_H
#define BLADETYPES_H

#include <Arduino.h>

// =====================================================
// Blade Operating Mode
// =====================================================

enum BladeMode {
    MODE_STABLE,
    MODE_UNSTABLE,
    MODE_RAINBOW,
    MODE_PULSE,
    MODE_FIRE,
    MODE_DARKSABER,
    MODE_CUSTOM
};

// =====================================================
// Blade Animation State
// =====================================================

enum BladeState {
    BLADE_OFF,
    BLADE_IGNITING,
    BLADE_ON,
    BLADE_RETRACTING,
    BLADE_LOCKUP,
    BLADE_MELT,
    BLADE_BLASTER,
    BLADE_DRAG
};

// =====================================================
// Blade Profiles
// =====================================================

enum BladeProfile {
    PROFILE_JEDI_BLUE,
    PROFILE_JEDI_GREEN,
    PROFILE_SITH_RED,
    PROFILE_MACE_PURPLE,
    PROFILE_AHSOKA_WHITE,
    PROFILE_KYLO,
    PROFILE_DARKSABER,
    PROFILE_FIRE,
    PROFILE_RAINBOW,
    PROFILE_CUSTOM
};

// =====================================================
// Blade Effect
// =====================================================
enum BladeEffect : uint16_t {

    EFFECT_NONE      = 0,

    EFFECT_FLICKER   = 1 << 0,

    EFFECT_UNSTABLE  = 1 << 1,

    EFFECT_PULSE     = 1 << 2,

    EFFECT_RAINBOW   = 1 << 3,

    EFFECT_FIRE      = 1 << 4,

    EFFECT_LOCKUP    = 1 << 5,

    EFFECT_DRAG      = 1 << 6,

    EFFECT_MELT      = 1 << 7

};

// =====================================================
// Blade Settings
// =====================================================

struct BladeSettings {

    // Color
    uint8_t r;
    uint8_t g;
    uint8_t b;

    // Brightness
    uint8_t brightness;

    // Current effect
    BladeMode mode;

    // Current profile
    BladeProfile profile;

    // Animation state
    BladeState state;

    // Number of LEDs currently lit
    uint16_t litPixels;

    // Total blade length
    uint16_t bladeLength;

    // Flags
    bool enabled;
    uint16_t effects;
};

#endif
