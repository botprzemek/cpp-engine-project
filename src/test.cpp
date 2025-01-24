// class Loot {
// private:
//     Inventory* inventory;
//     Item* key;
//     bool obtained;
//     bool locked;

// public:
//     Inventory* getInventory()  { return inventory; }
//     void setInventory(Inventory* newInventory) { inventory = newInventory; }

//     Item* getKey()  { return key; }
//     void setKey(Item* newKey) { key = newKey; }

//     bool isObtained()  { return obtained; }
//     void setObtained(bool status) { obtained = status; }

//     bool isLocked()  { return locked; }
//     void setLocked(bool status) { locked = status; }
// };

// class Race {
// public:
//     enum Type {
//         DARK_ELF,
//         DWARF,
//         GOBLIN,
//         HUMAN,
//         LIGHT_ELF,
//         ORC,
//     };

// private:
//     StatisticsModifier* modifier;

// public:
//     StatisticsModifier* getModifier()  { return modifier; }
//     void setModifier(StatisticsModifier* newModifier) { modifier = newModifier; }
// };

// class Class {
// public:
//     enum Type {
//         ARCHER,
//         BARD,
//         DRUID,
//         WARRIOR,
//         PALADIN,
//         RANGER,
//         WIZARD,
//     };

// private:
//     StatisticsModifier* modifier;

// public:
//     StatisticsModifier* getModifier()  { return modifier; }
//     void setModifier(StatisticsModifier* newModifier) { modifier = newModifier; }
// };

// class Equipment {
// private:
//     EquipmentItem* belt;
//     EquipmentItem* boots;
//     EquipmentItem* chest;
//     EquipmentItem* gloves;
//     EquipmentItem* head;
//     EquipmentItem* leggings;
//     EquipmentItem* necklace;
//     EquipmentItem* trinket;
//     Inventory* inventory;

// public:
//     EquipmentItem* getBelt()  { return belt; }
//     void setBelt(EquipmentItem* newBelt) { belt = newBelt; }

//     EquipmentItem* getBoots()  { return boots; }
//     void setBoots(EquipmentItem* newBoots) { boots = newBoots; }

//     EquipmentItem* getChest()  { return chest; }
//     void setChest(EquipmentItem* newChest) { chest = newChest; }

//     EquipmentItem* getGloves()  { return gloves; }
//     void setGloves(EquipmentItem* newGloves) { gloves = newGloves; }

//     EquipmentItem* getHead()  { return head; }
//     void setHead(EquipmentItem* newHead) { head = newHead; }

//     EquipmentItem* getLeggings()  { return leggings; }
//     void setLeggings(EquipmentItem* newLeggings) { leggings = newLeggings; }

//     EquipmentItem* getNecklace()  { return necklace; }
//     void setNecklace(EquipmentItem* newNecklace) { necklace = newNecklace; }

//     EquipmentItem* getTrinket()  { return trinket; }
//     void setTrinket(EquipmentItem* newTrinket) { trinket = newTrinket; }

//     Inventory* getInventory()  { return inventory; }
//     void setInventory(Inventory* newInventory) { inventory = newInventory; }
// };

// class PlayingEntity : public Entity {
// private:
//     Class* _class;
//     Equipment* equipment;
//     map<Skill::Type, Skill*> skills;

// public:
//     Class* getClass()  { return _class; }
//     void setClass(Class* newClass) { _class = newClass; }

//     Equipment* getEquipment()  { return equipment; }
//     void setEquipment(Equipment* newEquipment) { equipment = newEquipment; }

//     map<Skill::Type, Skill*> getSkills()  { return skills; }
//     void setSkills( map<Skill::Type, Skill*>& newSkills) { skills = newSkills; }
// };

// class Player : public PlayingEntity {
// public:
//     PlayerStatistics* getStatistics()  { return statistics; }
//     void setStatistics(PlayerStatistics* newStatistics) { statistics = newStatistics; }
// private:
//     PlayerStatistics* statistics;
// };

// class Enemy : public PlayingEntity {
// private:
//     EnemyStatistics* statistics;

// public:
//     EnemyStatistics* getStatistics()  { return statistics; }
//     void setStatistics(EnemyStatistics* newStatistics) { statistics = newStatistics; }
// };

// class Merchant : public Entity {
// private:
//     Inventory* offer;

// public:
//     Inventory* getOffer()  { return offer; }
//     void setOffer(Inventory* newOffer) { offer = newOffer; }
// };

// class Encounter {
// private:
//     Player* player;
//     Enemy* enemy;

// public:
//     Player* getPlayer()  { return player; }
//     void setPlayer(Player* newPlayer) { player = newPlayer; }

//     Enemy* getEnemy()  { return enemy; }
//     void setEnemy(Enemy* newEnemy) { enemy = newEnemy; }
// };

// class Inventory {
// public:
//     int getCurrency() {
//         return currency;
//     }
//     void setCurrency(int newCurrency) { currency = newCurrency; }

//     vector<Item*> getItems()  { return items; }
//     void setItems( vector<Item*>& newItems) { items = newItems; }
// private:
//     int currency;
//     vector<Item*> items;
// };

// class MerchantItem : public Item {
// private:
//     int buy_value;

// public:
//     int getBuyValue()  { return buy_value; }
//     void setBuyValue(int newBuyValue) { buy_value = newBuyValue; }
// };

// class EquipmentItem : public Item {
// public:
//     enum Slot {
//         BELT,
//         BOOTS,
//         CHEST,
//         GLOVES,
//         HEAD,
//         LEGGINGS,
//         NECKLECE,
//         TRINKET,
//     };

// private:
//     Slot slot;
//     int levelRequirement;

// public:
//     void setSlot(Slot newSlot) { slot = newSlot; }
//     void setLevelRequirement(int newLevelRequirement) { levelRequirement = newLevelRequirement; }
//     Slot getSlot()  { return slot; }

//     int getLevelRequirement()  { return levelRequirement; }
// };

// class ConsumableItem : public Item {
// private:
//     string effect;

// public:
//     string getEffect()  { return effect; }
//     void setEffect( string& newEffect) { effect = newEffect; }
// };

// class PlayerStatistics : public Statistics {
// private:
//     double experience;

// public:
//     double getExperience()  { return experience; }
//     void setExperience(double newExperience) { experience = newExperience; }
// };

// class EnemyStatistics : public Statistics {};

// class Skill {
// public:
//     Skill();
//     ~Skill();

//     enum Type {
//         FIREBALL,
//     };

// private:
//     string name;
//     string description;
//     int manaCost;
//     int levelRequirement;

// public:
//     string getName()  { return name; }
//     void setName( string& newName) { name = newName; }

//     string getDescription()  { return description; }
//     void setDescription( string& newDescription) { description = newDescription; }

//     int getManaCost()  { return manaCost; }
//     void setManaCost(int newManaCost) { manaCost = newManaCost; }

//     int getLevelRequirement()  { return levelRequirement; }
//     void setLevelRequirement(int newLevelRequirement) { levelRequirement = newLevelRequirement; }
// };

// class Rarity {
// public:
//     enum Type {
//         COMMON,
//         UNCOMMON,
//         RARE,
//         EPIC,
//         LEGENDARY,
//         MYTHIC,
//     };

//     string getName()  { return name; }
//     void setName( string& newName) { name = newName; }

//     int getChance()  { return chance; }
//     void setChance(int newChance) { chance = newChance; }
// private:
//     string name;
//     int chance;
// };

// class Entity {
// public:
//     string getFirstName() {
//         return firstName;
//     }
//     string getLastName() { return lastName; }
//     Race* getRace()  { return race; }
//     string getTitle()  { return title; }

//     void setFirstName( string& name) { firstName = name; }
//     void setLastName( string& name) { lastName = name; }
//     void setRace(Race* newRace) { race = newRace; }
//     void setTitle( string& name) { title = name; }
// private:
//     string firstName;
//     string lastName;
//     Race* race;
//     string title;
// };

// class Item {
// public:
//     Item();
//     ~Item();
// private:
//     Rarity* rarity;
//     string name;
//     string description;
//     int value;

// public:
//     Rarity* getRarity()  { return rarity; }
//     void setRarity(Rarity* newRarity) { rarity = newRarity; }

//     string getName()  { return name; }
//     void setName( string& newName) { name = newName; }

//     string getDescription()  { return description; }
//     void setDescription( string& newDescription) { description = newDescription; }

//     int getSoldValue()  { return value; }
//     void setSoldValue(int _value) { value = _value; }
// };