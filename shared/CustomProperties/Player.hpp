#pragma once

#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include <optional>
#include <type_traits>
#include "Photon/Pun/PhotonNetwork.hpp"
#include "Photon/Realtime/Player.hpp"
#include "Photon/Realtime/WebFlags.hpp"
#include "ExitGames/Client/Photon/Hashtable.hpp"
#include "System/Collections/Generic/KeyValuePair_2.hpp"
#include "System/Collections/Generic/InsertionBehavior.hpp"
#include "../Utils/Array.hpp"

namespace GorillaUtils::Player
{
    using PhotonNetwork = Photon::Pun::PhotonNetwork;
    using Player = Photon::Realtime::Player;
    using WebFlags = Photon::Realtime::WebFlags;
    using Hashtable = ExitGames::Client::Photon::Hashtable;
    using Hashtable_Base = System::Collections::Generic::Dictionary_2<Il2CppObject*, Il2CppObject*>;
    using InsertionBehavior = System::Collections::Generic::InsertionBehavior;
    using Pair = System::Collections::Generic::KeyValuePair_2<Il2CppObject*, Il2CppObject*>;

    /// @brief gets a property from the player custom properties
    /// @param player the player to get the property on
    /// @param property the name of the property
    /// @return optional template value, nullopt for no player, no properties or value nonexistent
    template <typename T> 
    std::optional<T> GetProperty(Player* player, std::string property)
    {
        static_assert(std::is_convertible<T, Il2CppObject*>::value || std::is_arithmetic<T>::value, "Property type should be convertible to Il2CppObject*, or be an arithmetic type");

        if (!player) return std::nullopt;
        Hashtable* properties = player->get_CustomProperties();
        if (!properties) return std::nullopt;

        Il2CppObject* propCS = reinterpret_cast<Il2CppObject*>(il2cpp_utils::newcsstr(property));
        if (!properties->Hashtable_Base::ContainsKey(propCS)) return std::nullopt;

        Il2CppObject* item = properties->get_Item(propCS);
        if (!item) return std::nullopt;

        if constexpr (std::is_pointer_v<T>) return (T)item;
        else return *(T*)item;
    }

    /// @brief sets a property on the player
    /// @param player the player to set on
    /// @param property the name of the property
    /// @param val the value to set
    template <typename T> 
    void SetProperty(Player* player, std::string property, T val)
    {
        static_assert(std::is_convertible<T, Il2CppObject*>::value || std::is_arithmetic<T>::value, "Property type should be convertible to Il2CppObject*, or be an arithmetic type");

        if (!player) return;
        Il2CppObject* key = reinterpret_cast<Il2CppObject*>(il2cpp_utils::newcsstr(property));
        Il2CppObject* value = il2cpp_utils::ToIl2CppObject(val);

        Hashtable* properties = *il2cpp_utils::New<Hashtable*>(1);
        // dont ask me why I am using a pair, but that makes it work properly
        Pair pair = Pair(key, value);

        // fucking long name but it funny
        properties->Hashtable_Base::System_Collections_Generic_ICollection$System_Collections_Generic_KeyValuePair$TKey_TValue$$_Add(pair);
        //properties->Hashtable_Base::Add(key, value);

        player->SetCustomProperties(properties, nullptr, WebFlags::_get_Default());
    }
}