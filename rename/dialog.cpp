#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //������
    #if 1
    //   <td height="30"><p align="center" class="STYLE4">��Ƭ(HTF Shorts)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\HTF_44_Swallow_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\A Hard Act To Swallow(��������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_58_Sucker_pt1_BB24_new.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\A Sucker For Love - Part 1(������1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_59_Sucker_pt2_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\A Sucker For Love - Part 2(������2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_53_Zoo_1_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\A to Zoo - Part 1(����԰1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_53_Zoo_2_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\A to Zoo - Part 2(����԰2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_62_Flocked_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\All Flocked Up(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_38_Bread_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Better Off Bread(�����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_51_Blind.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Blind Date(����Լ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_15_Boo_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Boo Do You Think You Are(���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_55_Cofin.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Can��t Stop Coffin(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_12_Chip_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Chip Off The Ol�� Block(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_36_Class_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Class Act(�༶����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_04_Antics_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Crazy Antics(��ͷ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_28_Eyecandy_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Eye Candy(�۾��ǹ�).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_32_Eyescold_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Eyes Cold Lemonade(�۾�����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_30_Flippin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Flippin�� Burgers(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_31_Whale_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Get Whale Soon(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_26_Trails1_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Happy Trails Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_27_Trails2_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Happy Trails Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_05_Ball_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Havin�� A Ball(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_47_Dolly_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Hello Dolly(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_03_Helping_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Helping Helps(ˮ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_14_Hide_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Hide and Seek(׽�Բ�).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_02_House_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\House Warming(�·���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_39_Trick_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\I Get a Trick Out of You(ħ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_66_I_Nub_h264.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\I Nub You(ͬ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_46_Icy_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Icy You(͵������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_21_Snap_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\It��s A Snap(�����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_54_Desert.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Just Desert(ɳĮ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_43_Reel_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Keeping It Reel(����Ӱ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_45_Slide_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Let It Slide(ˮ�ϻ���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_19_Meat_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Meat Me For Lunch(͵��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_34_Milkin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Milkin�� It(͵ţ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_16_Mime_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Mime And Mime Again(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_13_Tooth_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Nuttin�� But The Tooth(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_07_Nuttin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Nuttin�� Wrong With Candy(�ۻ���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_22_Hook_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Off The Hook(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_35_Sight_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Out Of Sight Out Of Mime(��ͷ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_42_Limb_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Out On A Limb(��ľ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_60_Peas_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Peas in a Pod(ħ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_09_Pitchin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Pitchin�� Impossible(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_56_Read_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Read ��Em and Weep(ħ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_48_Remains_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Remains To Be Seen(����Բ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_29_Rink_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Rink Hijinks(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_40_Shard_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Shard At Work(�Ե���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_50_Ski_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Ski Ya, Wouldn��t Wanna Be Ya(��ѩ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_33_Snip_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Snip Snip Hooray(��ͷ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_24_Snow_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Snow What(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_63_Fishy.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Something Fishy(������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_23_Spare_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Spare Me(������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_01_Spin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Spin Fun Knowin�� Ya(ת).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_10_Stayin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Stayin�� Alive(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_49_Spot_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Stealing The Spotlight(װ�ε�).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_52_Suck_BB24.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Suck It Up(��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_20_Sweet_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Sweet Ride(�����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_65_Swelter_h264.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Swelter Skelter(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_37_Wheel_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\The Way You Make Me Wheel(��·ɥ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_25_Knife_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\This Is Your Knife(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_18_Tongue_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Tongue Twister(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_11_Treasure_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Treasure These Idol Moments(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_41_Water_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Water Way To Go(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_06_Water_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Water You Wading For(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_57_Scrooged.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\We��re Scrooged(��������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_08_Wheelin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Wheelin�� And Dealin��(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_WhosLine.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Whose Line Is It Anyway(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_64_Hitch_H264.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Without A Hitch(�).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_61_Wrath_HD.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\Wrath of Con(������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_17_Bakin_640.flv", "F:\\HappyTreeFriends\\��Ƭ(HTF Shorts)\\You��re Baking Me Crazy(�ٶ�).flv");



    //    <td height="30"><p align="center" class="STYLE4">ӰƬ(TV Episodes)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\HTF_S02_Sink_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\And the Kitchen Sink - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S02_Sink_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\And the Kitchen Sink - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S14_Wish_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\As You Wish - Part 1(���1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S14_Wish_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\As You Wish - Part 2(���2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S36_Authopsy_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Autopsy Turvy (Double Whammy - Part 3)(˫���˸�3).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S36_Authopsy_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Autopsy Turvy (Double Whammy - Part 4)(˫���˸�4).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S25_Blast_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Blast From the Past - Part 1(ʱ���1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S25_Blast_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Blast From the Past - Part 2(ʱ���2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S21_Heart_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Change of Heart - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S21_Heart_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Change of Heart - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Chew_pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Chew Said A Mouthful - Part 1(������1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Chew_pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Chew Said A Mouthful - Part 2(������2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S13_Concrete_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Concrete Solution - Part 1(������1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S13_Concrete_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Concrete Solution - Part 2(������2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S16_Doggone_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Doggone It! - Part 1(�蹷1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S16_Doggone_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Doggone It! - Part 2(�蹷2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S17_Chain_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Don��t Yank My Chain - Part 1(Խ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S17_Chain_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Don��t Yank My Chain - Part 2(Խ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S35_Whammy_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Double Whammy - Part 1(˫���˸�1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S35_Whammy_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Double Whammy - Part 2(˫���˸�2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S08_Dunce_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Dunce Upon A Time - Part 1(�칬1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S08_Dunce_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Dunce Upon A Time - Part 2(�칬2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S29_Comb_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Easy Comb, Easy Go - Part 1(����ˮ1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S29_Comb_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Easy Comb, Easy Go - Part 2(����ˮ2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S12_Sleigh_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Easy For You To Sleigh - Part 1(ʥ��С͵1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S12_Sleigh_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Easy For You To Sleigh - Part 2(ʥ��С͵2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S11_Litter_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Every Litter Bit Hurts - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S11_Litter_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Every Litter Bit Hurts - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S03_Gems_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Gems the Breaks - Part 1(�̱�ʯ1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S03_Gems_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Gems the Breaks - Part 2(�̱�ʯ2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S01_Hero_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Hero to Eternity - Part 1(Ӣ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S01_Hero_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Hero to Eternity - Part 2(Ӣ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S20_Hole_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Hole Lotta Love - Part 1(�ض�1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S20_Hole_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Hole Lotta Love - Part 2(�ض�2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S22_Home_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Home Is Where The Hurt Is - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S22_Home_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Home Is Where The Hurt Is - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S23_Idol_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Idol Curiosity - Part 1(����3).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S23_Idol_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Idol Curiosity - Part 2(����4).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S37_Jam_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\In A Jam - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S37_Jam_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\In A Jam - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S09_Fitso_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Ipso Fatso - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S09_Fitso_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Ipso Fatso - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\htf_39_junk_trunk_1_700.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Junk in the Truck - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\htf_39_junk_trunk_2_500.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Junk in the Truck - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S21_Mime_Part1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Mime to Five - Part 1(��ְ1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S21_Mime_Part2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Mime to Five - Part 2(��ְ2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S10_Party_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Party Animal - Part 1(�������1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S10_Party_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Party Animal - Part 2(�������2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S18_Sea_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Sea What I Found - Part 1(Ѱ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S18_Sea_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Sea What I Found - Part 2(Ѱ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S24_Develops_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\See What Develops - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S24_Develops_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\See What Develops - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S19_Sight_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Sight for Sore Eyes - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S19_Sight_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Sight for Sore Eyes - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S06_Snow_Part1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Snow Place To Go - Part 1(����ѩ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S06_Snow_Part2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Snow Place To Go - Part 2(����ѩ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S05_Hike_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Take A Hike - Part 1(Զ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S05_Hike_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Take A Hike - Part 2(Զ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S04_Track_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\The Wrong Side of the Tracks - Part 1(��ɽ��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S04_Track_Pt2.mov.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\The Wrong Side of the Tracks - Part 2(��ɽ��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF-S32-Tongue_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Tongue in Cheek - Part 1(ң��1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF-S32-Tongue_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Tongue in Cheek - Part 2(ң��2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S07_Flame_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Who��s to Flame - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S07_Flame_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Who��s to Flame - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S28_Wing_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wingin�� It - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S28_Wing_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wingin�� It - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S33_Wipe_Pt_1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wipe Out! - Part 1(����1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S33_Wipe_Pt_2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wipe Out! - Part 2(����2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S09_Wishy_Pt1.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wishy Washy - Part 1(���1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_S09_Wishy_Pt2.flv", "F:\\HappyTreeFriends\\ӰƬ(TV Episodes)\\Wishy Washy - Part 2(���2).flv");



    //    <td height="30"><p align="center" class="STYLE4">����ӡ��(Love Bites)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\HTF_LB_Love_1280x720.flv", "F:\\HappyTreeFriends\\����ӡ��(Love Bites)\\I Heart U(���Ļ���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_LB_SeaOfLove_HD_1280x720.flv", "F:\\HappyTreeFriends\\����ӡ��(Love Bites)\\Sea of Love(��֮��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_LB_ColdHearted_HD_1280x720.flv", "F:\\HappyTreeFriends\\����ӡ��(Love Bites)\\Cold Hearted(ä��).flv");




    //    <td height="30"><p align="center" class="STYLE4">������(Irregulars)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\HTF_BanjoFrenzy_720.flv", "F:\\HappyTreeFriends\\������(Irregulars)\\Banjo Frenzy(������).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF-FOB_NTSC_24.flv", "F:\\HappyTreeFriends\\������(Irregulars)\\Carpal Tunnel of Love(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_False_pt1.flv", "F:\\HappyTreeFriends\\������(Irregulars)\\False Alarm - Part 1(��پ���1).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_False_pt2.flv", "F:\\HappyTreeFriends\\������(Irregulars)\\False Alarm - Part 2(��پ���2).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_SkiPatrol_2.flv", "F:\\HappyTreeFriends\\������(Irregulars)\\Ski Patrol(��ѩ����).flv");



    //    <td height="30"><p align="center" class="STYLE4">�ؿ�(Kringles)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\htf_08_chill_kringle.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Chill Kringle(ѩ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Kringles_Kitchen.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Kitchen Kringle(ҹ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Kringles_Reindeer.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Reindeer Kringle(¹).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Kringles_Ski.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Ski Kringle(��ѩ).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_07_Kringles_Strain.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Strain Kringle(��ѩ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Kringles_Train.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Train Kringle(С��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Kringles_Tree.flv", "F:\\HappyTreeFriends\\�ؿ�(Kringles)\\Tree Kringle(��).flv");



    //    <td height="30"><p align="center" class="STYLE4">����Ƭ�ؼ�(KA-POW!)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\BooksOfFurry.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\Buddhist Monkey - Books of Fury(��).flv");
    QFile::copy("F:\\HappyTreeFriends\\EnterTheGarden.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\Buddhist Monkey - Enter The Garden(����ʹ��).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_01_KaPow_3Courses_H264_1280x720_new.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\Buddhist Monkey - Three Courses of Death(����).flv");
    QFile::copy("F:\\HappyTreeFriends\\MoleInTheCity.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\Mole In The City(���).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_03_KaPow_Spledid_H264_1280x720.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\Splendid��s SSSSSuper Squad - Mirror, Mirror(���˶Ծ�).flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_02_KaPow_Operation_H264_1280x720.flv", "F:\\HappyTreeFriends\\����Ƭ�ؼ�(KA-POW!)\\W.A.R. Journal - Operation - Tiger Bomb(����ը��).flv");



    //    <td height="30"><p align="center" class="STYLE4">������Ļ��(Break)</p></td>
    QFile::copy("F:\\HappyTreeFriends\\HTF_DVD_Abestos.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Asbestos I Can Do.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Behind_the_Screams.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Behind The Screams.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_ChoreLoser.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Chore Loser.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_Caroling_Deck_The_Holes.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Deck the Halls.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_HateMail.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Hate Mail.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_SeizeTheDay.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Seize The Day.flv");
    QFile::copy("F:\\HappyTreeFriends\\Something_Fishy_Rec.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Something Fishy Voice-Over Session.flv");
    QFile::copy("F:\\HappyTreeFriends\\Trainspotting.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Under The Skin of Happy Tree Friends.flv");
    QFile::copy("F:\\HappyTreeFriends\\HTF_VOices.flv", "F:\\HappyTreeFriends\\������Ļ��(Break)\\Voices of Doom.flv");

    qDebug() << "copy end";
#endif
}
