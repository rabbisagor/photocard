#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct DeveloperProfile {
    std::string name;
    std::string title;
    std::string githubUser;
    std::vector<std::string> topSkills;
    std::string statusText;
};

class PhotoCardGenerator {
private:
    DeveloperProfile profile;

public:
    PhotoCardGenerator(DeveloperProfile devProfile) : profile(devProfile) {}

    // কাস্টম স্টাইলিশ SVG ফটোকার্ড জেনারেট করার মেথড
    std::string generateSVG() {
        std::string svg = "";

        // SVG ক্যানভাস এবং গ্রেডিয়েন্ট ডেফিনিশন
        svg += "<svg width=\"500\" height=\"280\" viewBox=\"0 0 500 280\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\">\n";
        svg += "  <style>\n";
        svg += "    .header { font: bold 22px 'Segoe UI', Ubuntu, Sans-Serif; fill: #00F5FF; }\n";
        svg += "    .sub-header { font: 600 14px 'Segoe UI', Ubuntu, Sans-Serif; fill: #FF007F; }\n";
        svg += "    .text { font: 400 13px 'Segoe UI', Ubuntu, Sans-Serif; fill: #E0E0E0; }\n";
        svg += "    .tag { font: 600 11px 'Segoe UI', Ubuntu, Sans-Serif; fill: #0D1117; }\n";
        svg += "    .status { font: italic 12px 'Segoe UI', Ubuntu, Sans-Serif; fill: #00FF66; }\n";
        svg += "  </style>\n\n";

        // ব্যাকগ্রাউন্ড এবং নিয়ন বর্ডার
        svg += "  <rect width=\"500\" height=\"280\" rx=\"16\" fill=\"#0D1117\" />\n";
        svg += "  <rect x=\"2\" y=\"2\" width=\"496\" height=\"276\" rx=\"14\" stroke=\"url(#grad_border)\" stroke-width=\"2\" />\n\n";

        // কালার গ্রেডিয়েন্ট ডেফিনিশন
        svg += "  <defs>\n";
        svg += "    <linearGradient id=\"grad_border\" x1=\"0%\" y1=\"0%\" x2=\"100%\" y2=\"100%\">\n";
        svg += "      <stop offset=\"0%\" stop-color=\"#00F5FF\" />\n";
        svg += "      <stop offset=\"50%\" stop-color=\"#FF007F\" />\n";
        svg += "      <stop offset=\"100%\" stop-color=\"#7928CA\" />\n";
        svg += "    </linearGradient>\n";
        svg += "    <linearGradient id=\"tag_grad\" x1=\"0%\" y1=\"0%\" x2=\"100%\" y2=\"0%\">\n";
        svg += "      <stop offset=\"0%\" stop-color=\"#00F5FF\" />\n";
        svg += "      <stop offset=\"100%\" stop-color=\"#00FF66\" />\n";
        svg += "    </linearGradient>\n";
        svg += "  </defs>\n\n";

        // গিটহাব অবতার / প্রোফাইল সার্কেল প্লেসহোল্ডার
        svg += "  <circle cx=\"75\" cy=\"75\" r=\"35\" stroke=\"url(#grad_border)\" stroke-width=\"3\" fill=\"#161B22\" />\n";
        svg += "  <text x=\"75\" y=\"80\" text-anchor=\"middle\" class=\"header\" font-size=\"26\">" + std::string(1, profile.name[0]) + "</text>\n\n";

        // নাম ও টাইটেল
        svg += "  <text x=\"130\" y=\"65\" class=\"header\">" + profile.name + "</text>\n";
        svg += "  <text x=\"130\" y=\"88\" class=\"sub-header\">" + profile.title + "</text>\n";
        svg += "  <text x=\"130\" y=\"110\" class=\"status\">● " + profile.statusText + "</text>\n\n";

        // ডিভাইডার লাইন
        svg += "  <line x1=\"40\" y1=\"135\" x2=\"460\" y2=\"135\" stroke=\"#30363D\" stroke-width=\"1\" />\n\n";

        // দক্ষতা / টেক স্কিলস ব্যাজ (Skills Badges)
        svg += "  <text x=\"40\" y=\"165\" class=\"text\" font-weight=\"bold\">Top Tech Stack:</text>\n";

        int xPos = 40;
        int yPos = 180;
        for (const auto& skill : profile.topSkills) {
            int width = skill.length() * 9 + 20;
            svg += "  <rect x=\"" + std::to_string(xPos) + "\" y=\"" + std::to_string(yPos) +
                   "\" width=\"" + std::to_string(width) + "\" height=\"24\" rx=\"12\" fill=\"url(#tag_grad)\" />\n";
            svg += "  <text x=\"" + std::to_string(xPos + width / 2) + "\" y=\"" + std::to_string(yPos + 16) +
                   "\" text-anchor=\"middle\" class=\"tag\">" + skill + "</text>\n";
            xPos += width + 10;
        }

        // গিটহাব হ্যান্ডেল ও ফুটার
        svg += "  <text x=\"40\" y=\"245\" class=\"text\">GitHub: <tspan fill=\"#00F5FF\">github.com/" + profile.githubUser + "</tspan></text>\n";
        svg += "  <text x=\"460\" y=\"245\" text-anchor=\"end\" class=\"text\" fill=\"#8B949E\">Built with C++</text>\n";

        svg += "</svg>";
        return svg;
    }

    // ফাইল হিসেবে সংরক্ষণ
    void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << generateSVG();
            outFile.close();
            std::cout << "Successfully generated: " << filename << std::endl;
        } else {
            std::cerr << "Error: Could not save file!" << std::endl;
        }
    }
};

int main() {
    // ডেটা কনফিগারেশন
    DeveloperProfile myProfile;
    myProfile.name = "Selim Reza";
    myProfile.title = "C++ & Systems Developer";
    myProfile.githubUser = "your-username";
    myProfile.statusText = "Building cool C++ tools";
    myProfile.topSkills = {"C++20", "Algorithms", "Git", "Linux", "OpenGL"};

    // জেনারেট এবং সেভ করা
    PhotoCardGenerator generator(myProfile);
    generator.saveToFile("github_photocard.svg");

    return 0;
}
