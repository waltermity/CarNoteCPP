#include "Tesztek.h"
void mytests() {
    Jarmu* m = new Motor("Asd", 2002, "Kavasaki...", 1000);
    Jarmu* a = new Auto("Asd2", 2009, "Opel Astra", 5, "kombi");
    Jarmu* t = new Teherauto("Asd1", 2012, "Mercedes...", 3400);
    //Inic test
    TEST("Osztaly inic", "Motor")
        EXPECT_STREQ("Motor", m->GetJarmuTipus().c_str());
    END

        TEST("Osztaly inic", "Auto")
        EXPECT_STREQ("Auto", a->GetJarmuTipus().c_str());
    END

        TEST("Osztaly inic", "Teherauto")
        EXPECT_STREQ("Teherauto", t->GetJarmuTipus().c_str());
    END
//----------------------------------
//ADD ADAT TEST
        TEST("Adat hozzaadas", "Hibas osszeg")
        EXPECT_ANY_THROW(m->AddAdat("2012.11.20", -1, 10050, "Nincs"));
    END

        TEST("Adat hozzaadas", "Hibas kmallas")
        EXPECT_ANY_THROW(m->AddAdat("2012.11.20", 10050, -1, "Nincs"));
    END

        m->AddAdat("2012.11.20", 10000, 15000, "Nincs");
    TEST("Adat hozzaadas", "Km es osszeg valtozas")
        EXPECT_EQ(10000, m->GetOsszkiadas());
    EXPECT_EQ(15000, m->Getmaxkm());
    END

        m->AddAdat("2012.11.21", 10000, 16000, "Nincs");
    TEST("Adat hozzaadas", "Km es osszeg valtozas")
        EXPECT_EQ(20000, m->GetOsszkiadas());
    EXPECT_EQ(16000, m->Getmaxkm());
    END
//---------------------------------------------------
//REMOVE ADAT Test
        TEST("Adat torles", "Hibas index")
        EXPECT_ANY_THROW(m->RemoveAdat(-1));
    EXPECT_ANY_THROW(m->RemoveAdat(3));
    EXPECT_ANY_THROW(a->RemoveAdat(1));
    END

        m->RemoveAdat(0);
    TEST("Adat torles", "Torles kovetkezmenyei")
        EXPECT_EQ(10000, m->GetOsszkiadas());
    EXPECT_EQ(15000, m->Getmaxkm());
    END

        m->RemoveAdat(0);
    TEST("Adat torles", "Torles kovetkezmenyei")
        EXPECT_EQ(0, m->GetOsszkiadas());
    EXPECT_EQ(0, m->Getmaxkm());
    END
//----------------------------------------------
    Jarmuvek* jm = new Jarmuvek();
    Jarmuvek* ja = new Jarmuvek();
    Jarmuvek* jt = new Jarmuvek();
    int db = 3;
    jm->jamru = m;
    jm->next = ja;
    ja->jamru = a;
    ja->next = jt;
    jt->jamru = t;
    DelJarmu(&jm, &db, 1);
    TEST("Adat torles jarmuvek", "Torles kovetkezmenyei") 
        EXPECT_EQ(2, db);
        EXPECT_EQ(jm->next, jt);
    END
    DelJarmu(&jm, &db, 0);
    DelJarmu(&jm, &db, 0);
}