#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()){
            if (poseHandler.IsReverse()){
                poseHandler.Backward();
            }
            else{
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()){
            poseHandler.Backward();
        }
        else{
            poseHandler.Forward();
        }
    }
};
class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
            poseHandler.TurnRight();
        } else {
            poseHandler.Forward();
            poseHandler.TurnLeft();
        }
    }
};
class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        }
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
            poseHandler.TurnLeft();
        } else {
            poseHandler.Forward();
            poseHandler.TurnRight();
        }
    }
};
class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};
}