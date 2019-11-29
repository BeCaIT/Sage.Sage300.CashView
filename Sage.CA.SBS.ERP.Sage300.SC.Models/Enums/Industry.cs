using Sage.CA.SBS.ERP.Sage300.Common.Models;
using Sage.CA.SBS.ERP.Sage300.SC.Resources.Forms.Enums;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sage.CA.SBS.ERP.Sage300.SC.Models.Enums
{
    public enum Industry
    {
        [EnumValue(nameof(Unspecified), typeof(IndustryResx))]
        [StoredAsChar]
        Unspecified = ' ',
    }


    public enum IndustrySG
    {
        [EnumValue(nameof(Unspecified), typeof(IndustrySGResx))]
        [StoredAsChar]
        Unspecified = ' ',

        [EnumValue(nameof(A), typeof(IndustrySGResx))]
        [StoredAsChar]
        A = 'A',

        [EnumValue(nameof(B), typeof(IndustrySGResx))]
        [StoredAsChar]
        B = 'B',

        [EnumValue(nameof(C), typeof(IndustrySGResx))]
        [StoredAsChar]
        C = 'C',

        [EnumValue(nameof(D), typeof(IndustrySGResx))]
        [StoredAsChar]
        D = 'D',

        [EnumValue(nameof(E), typeof(IndustrySGResx))]
        [StoredAsChar]
        E = 'E',

        [EnumValue(nameof(F), typeof(IndustrySGResx))]
        [StoredAsChar]
        F = 'F',

        [EnumValue(nameof(G), typeof(IndustrySGResx))]
        [StoredAsChar]
        G = 'G',

        [EnumValue(nameof(H), typeof(IndustrySGResx))]
        [StoredAsChar]
        H = 'H',

        [EnumValue(nameof(I), typeof(IndustrySGResx))]
        [StoredAsChar]
        I = 'I',

        [EnumValue(nameof(J), typeof(IndustrySGResx))]
        [StoredAsChar]
        J = 'J',

        [EnumValue(nameof(K), typeof(IndustrySGResx))]
        [StoredAsChar]
        K = 'K',

        [EnumValue(nameof(L), typeof(IndustrySGResx))]
        [StoredAsChar]
        L = 'L',

        [EnumValue(nameof(M), typeof(IndustrySGResx))]
        [StoredAsChar]
        M = 'M',

        [EnumValue(nameof(N), typeof(IndustrySGResx))]
        [StoredAsChar]
        N = 'N',

        [EnumValue(nameof(O), typeof(IndustrySGResx))]
        [StoredAsChar]
        O = 'O',

        [EnumValue(nameof(P), typeof(IndustrySGResx))]
        [StoredAsChar]
        P = 'P',

        [EnumValue(nameof(Q), typeof(IndustrySGResx))]
        [StoredAsChar]
        Q = 'Q',

        [EnumValue(nameof(R), typeof(IndustrySGResx))]
        [StoredAsChar]
        R = 'R',

        [EnumValue(nameof(S), typeof(IndustrySGResx))]
        [StoredAsChar]
        S = 'S',

        [EnumValue(nameof(T), typeof(IndustrySGResx))]
        [StoredAsChar]
        T = 'T',

        [EnumValue(nameof(U), typeof(IndustrySGResx))]
        [StoredAsChar]
        U = 'U',

        [EnumValue(nameof(V), typeof(IndustrySGResx))]
        [StoredAsChar]
        V = 'V',
    }

    public enum IndustryMY
    {
        [EnumValue(nameof(Unspecified), typeof(IndustryMYResx))]
        [StoredAsChar]
        Unspecified = ' ',

        [EnumValue(nameof(A), typeof(IndustryMYResx))]
        [StoredAsChar]
        A = 'A',

        [EnumValue(nameof(B), typeof(IndustryMYResx))]
        [StoredAsChar]
        B = 'B',

        [EnumValue(nameof(C), typeof(IndustryMYResx))]
        [StoredAsChar]
        C = 'C',

        [EnumValue(nameof(D), typeof(IndustryMYResx))]
        [StoredAsChar]
        D = 'D',

        [EnumValue(nameof(E), typeof(IndustryMYResx))]
        [StoredAsChar]
        E = 'E',

        [EnumValue(nameof(F), typeof(IndustryMYResx))]
        [StoredAsChar]
        F = 'F',

        [EnumValue(nameof(G), typeof(IndustryMYResx))]
        [StoredAsChar]
        G = 'G',

        [EnumValue(nameof(H), typeof(IndustryMYResx))]
        [StoredAsChar]
        H = 'H',

        [EnumValue(nameof(I), typeof(IndustryMYResx))]
        [StoredAsChar]
        I = 'I',

        [EnumValue(nameof(J), typeof(IndustryMYResx))]
        [StoredAsChar]
        J = 'J',

        [EnumValue(nameof(K), typeof(IndustryMYResx))]
        [StoredAsChar]
        K = 'K',
    }
}
