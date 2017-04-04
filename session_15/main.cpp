//
// Created by jlgerber on 4/3/17.
//

#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include "yaml-cpp/yaml.h"

void simpleYaml() {
    // load the root node
    YAML::Node node = YAML::Load("[1,2,3]");
    // verify that we have a sequence
    assert(node.Type() == YAML::NodeType::Sequence);
    // loop over
    std::cout << std::endl << "Traditional" << std::endl << std::endl;
    for(std::size_t i=0; i < node.size(); i++) {
        std::cout << node[i].as<int>() << "\n";
    }
    std::cout << std::endl << "Iterator Style" << std::endl << std::endl;
    for(YAML::const_iterator i=node.begin(); i!= node.end(); ++i) {
        std::cout << i->as<int>() << std::endl;
    }
}

void readBooks() {
    YAML::Node booksroot = YAML::LoadFile("../../session_15/books.yaml");
    assert(booksroot.IsSequence());
    std::cout << std::endl << "Reading books.yaml" << std::endl << std::endl;
    for(YAML::const_iterator it=booksroot.begin(); it != booksroot.end(); ++it) {
        for(YAML::const_iterator mip = it->begin(); mip != it->end(); ++mip) {
            std::cout << "key: " << std::left << std::setw(8) << mip->first.as<std::string>() << " value: " << mip->second.as<std::string>() << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "You can also use bracket notation to access lists and dictionaries" << std::endl << std::endl;
    std::cout << "Unlike the STL, providing invalid key simply returns nothing" << std::endl;
    if(booksroot[0] and booksroot[0]["author"])
        std::cout << booksroot[0]["author"] << " wrote \"" << booksroot[0]["name"] << "\"" << std::endl;
    else
        std::cout << "I suppose that I have asked for something which doesn't exist." << std::endl;

    std::cout << std::endl;
    std::cout << "booksroot[0] is a ";
    switch (booksroot[0].Type()) {
        case YAML::NodeType::Null: std::cout << "Null" << std::endl; break;
        case YAML::NodeType::Scalar: std::cout << "Scalar" << std::endl;  break;
        case YAML::NodeType::Sequence: std::cout << "Sequence" << std::endl;  break;
        case YAML::NodeType::Map: std::cout << "Map" << std::endl;  break;
        case YAML::NodeType::Undefined: std::cout << "undefined" << std::endl;  break;
    }

}

void writeYaml() {
    std::cout << std::endl << "Testing Yaml output" << std::endl;
    YAML::Emitter out;
    out << "this is a test";
    std::cout << out.c_str() << std::endl;

    std::cout << std::endl << "more complicated fair. How about a seuqence?" << std::endl << std::endl;
    YAML::Emitter out2;
    out2 << YAML::BeginSeq;
    out2 << "eggs";
    out2 << "bread";
    out2 << "milk" ;
    out2 << "cheese";
    out2 << YAML::EndSeq;
    std::cout << out2.c_str() << std::endl << std::endl;

    std::cout << "And Maps" << std::endl <<std::endl;
    YAML::Emitter out3;
    out3 << YAML::BeginMap;
    out3 << YAML::Key << "author";
    out3 << YAML::Value << "Haruki Mirukami";
    out3 << YAML::Key << "name";
    out3 << YAML::Value << "South of the Border, West of the Sun";
    out3 << YAML::EndMap;

    std::cout << out3.c_str() << std::endl << std::endl;
}

void aliasAnchor() {
    YAML::Emitter out;
    out << YAML::BeginSeq;
    out << YAML::Anchor("fred");
    out << YAML::BeginMap;
    out << YAML::Key << "name" << YAML::Value << "Fred";
    out << YAML::Key << "age" << YAML::Value << "42";
    out << YAML::EndMap;
    out << YAML::Alias("fred");
    out << YAML::EndSeq;
    std::cout << std::endl << "alias and anchor" << std::endl << std::endl << out.c_str() << std::endl;

}

void customManips() {
    YAML::Emitter out3;
    out3.SetIndent(8);
    out3.SetMapFormat(YAML::Flow);
    //out3.SetSeqFormat(YAML::Flow);
    out3 << YAML::BeginSeq;
    out3 << YAML::BeginMap;
    out3 << YAML::Key << "author";
    out3 << YAML::Value << "Haruki Mirukami";
    out3 << YAML::Key << "name";
    out3 << YAML::Value << "South of the Border, West of the Sun";
    out3 << YAML::EndMap;

    out3 << "eggs";
    out3 << "bread";
    out3 << "milk" ;
    out3 << "cheese";
    out3 << YAML::EndSeq;
    std::cout << std::endl << "custom manipulators" << std::endl << std::endl;
    std::cout << out3.c_str() << std::endl;
}

void overloadedContainers() {
   std::vector<std::string> v;
    v.push_back("Vladimir Nabokov");
    v.push_back("Italo Calvino");
    v.push_back("Umberto Eco");
    v.push_back("Haruki Mirukami");
    v.push_back("Michael Ondaatje");
    v.push_back("Thomas Wolfe");
    v.push_back("Kazio Ishiguro");
    v.push_back("Thomas Pynchon");
    YAML::Emitter out;
    out << v;
    std::cout << std::endl << "handling a vector of strings" << std::endl << std::endl;
    std::cout << out.c_str() << std::endl;
}

// Custom class / struct support.
struct Vec3 {
    double m_x, m_y, m_z;

     Vec3() : m_x{0}, m_y{0}, m_z{0} {};

     Vec3(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {};

    bool operator==(const Vec3& lhs) const {
        return m_x == lhs.m_x && m_y == lhs.m_y && m_z == lhs.m_z;
    }
};

namespace YAML {
template<>
struct convert<Vec3> {
    static Node encode(const Vec3& rhs) {
        Node node;
        node.push_back(rhs.m_x);
        node.push_back(rhs.m_y);
        node.push_back(rhs.m_z);
        return node;
    }

    static bool decode(const Node &node, Vec3 &rhs) {
        if(!node.IsSequence() || node.size() != 3) {
            return false;
        }

        rhs.m_x = node[0].as<double>();
        rhs.m_y = node[1].as<double>();
        rhs.m_z = node[2].as<double>();
        return true;
    }
};

    Emitter& operator<<(Emitter& out, const Vec3 &v) {
        out << YAML::Flow << YAML::BeginSeq  << v.m_x << v.m_y << v.m_z << YAML::EndSeq;
        return out;
    }
}
void customClassSupport() {
    YAML::Node node = YAML::Load("start: [1, 3, 0]");
    Vec3 v = node["start"].as<Vec3>();
    std::cout << std::endl << "Reading in YAML string into Vec3" << std::endl << std::endl;
    std::cout << "Vec3<" << v.m_x << ", " << v.m_y << ", " << v.m_z << ">\n\n";

    Vec3 vc(1,2,3);

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "start";
    out << YAML::Value << vc;
    out << YAML::EndMap;

    std::cout << "Output Vec3 to Yaml directly" << std::endl << std::endl;
    std::cout << out.c_str() << std::endl;

}
int main() {
    simpleYaml();
    readBooks();
    writeYaml();
    aliasAnchor();
    customManips();
    overloadedContainers();
    customClassSupport();
    return 0;
}
