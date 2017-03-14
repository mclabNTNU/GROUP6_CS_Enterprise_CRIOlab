clear all

inputDPgains

if(isdiag(K2)&&max(K2(:))==1)
    disp('K2 is an identity matrix. Yay!')
else
    disp('K2 is not an identity matrix. You dun fooked opp good boy.')
    return
end

if(issymmetric(L1)&&issymmetric(L2)&&issymmetric(L3))
    disp('L1, L2, and L3 are symmetric. Good on yah Bobby!')
else
    disp('Google yourself symmetric matrices. Bozo.')
    return
end

if(L1*L3==L3*L1)
    disp('L1 and L3 are commutative. Dont scew it up now!')
else
    disp('L1 and L3 are not commutative. Do not pass go, do not collect 200 dollahs.')
    return
end

if(min(eig(L1*L2+L2*L1-2*L3))>=0&&min(eig(inv(L3)*L1-inv(L2)))>=0)
    disp('ALL GOOD. What a man. What a cheese. What a beer.')
else
    if(min(eig(L1*L2+L2*L1-2*L3))>=0)
        disp('L1*L2+L2*L1-2*L3 is ok, so inv(L3)*L1-inv(L2 must be yer problem')
        return
    elseif(min(eig(inv(L3)*L1-inv(L2)))>=0)
        disp('L1*L2+L2*L1-2*L3 is fucked.')
        return
    else
        disp('Its all gone to shit at the end')
    end
end



