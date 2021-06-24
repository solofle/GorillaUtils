#pragma once
#include "../Utils/Array.hpp"
#include "Photon/Pun/PhotonView.hpp"
#include "Photon/Pun/RpcTarget.hpp" 
#include "Photon/Realtime/Player.hpp"

namespace GorillaUtils::RPC
{
    using PhotonView = Photon::Pun::PhotonView;
    using RpcTarget = Photon::Pun::RpcTarget;
    using Player = Photon::Realtime::Player;

    template <typename... Tparams>
    void RPC(PhotonView* photonView, std::string method, RpcTarget target, Tparams&&... params)
    {
        if (!photonView) return;
        Il2CppString* methodName = il2cpp_utils::newcsstr(method);

        constexpr auto numargs {sizeof...(params)};

        Array<Il2CppObject*>* arr = reinterpret_cast<Array<Il2CppObject*>*>(il2cpp_functions::array_new(classof(Il2CppObject*), numargs));
        if constexpr (numargs > 0) GorillaUtils::ArrayUtils::box_array(arr, params...);

        photonView->RPC(methodName, target, arr);
    }

    template <typename... Tparams>
    void RPC(PhotonView* photonView, std::string method, Player* target, Tparams&&... params)
    {
        if (!photonView) return;
        Il2CppString* methodName = il2cpp_utils::newcsstr(method);

        constexpr auto numargs {sizeof...(params)};

        Array<Il2CppObject*>* arr = reinterpret_cast<Array<Il2CppObject*>*>(il2cpp_functions::array_new(classof(Il2CppObject*), numargs));
        if constexpr (numargs > 0) GorillaUtils::ArrayUtils::box_array(arr, params...);

        photonView->RPC(methodName, target, arr);
    }
}