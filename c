#!/bin/bash -xe

qmk clean
qmk compile -kb szrkbd/debug -km default
