/*
 * Copyright (c) 2017 micro framework workers, All rights reserved.
 *
 * Terms for redistribution and use can be found in LICENCE.
 */

/**
 * @file Validator.h
 * @brief Simple data validators
 *
 * These validators take an arbitrary piece of data and return a boolean value.
 */


#ifndef INC_VALIDATOR_H
#define INC_VALIDATOR_H

#include "compiler.h"

namespace MicroFrameWork {

/**
 * Trivial validator, that always returns true.
 *
 * This is the default validator used by the Setting class.
 */
template <typename T>
class TrivialValidator {
public:
    TrivialValidator(){};
    bool
    operator()(UNUSED T v) const {
        return true;
    };
};

/**
 * Validator for values to fall into a given range
 *
 * Given a value, this operator returns true, if the value falls within a range
 * (defined at instance construction time). The test includes the limits of the
 * range.
 *
 * The data type used with this validator has to have the <= and >= operators
 * defined for it.
 */
template <typename T>
class RangeValidator {
public:
    RangeValidator(T min_, T max_) : min(min_), max(max_){};
    bool
    operator()(const T v) const {
        return v >= min && v <= max;
    };

private:
    const T min;
    const T max;
};
}

#endif /* INC_VALIDATOR_H */
