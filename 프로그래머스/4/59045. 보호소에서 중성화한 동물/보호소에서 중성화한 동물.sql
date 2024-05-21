-- 코드를 입력하세요
SELECT ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.ANIMAL_TYPE, ANIMAL_OUTS.NAME
FROM ANIMAL_INS
    RIGHT JOIN ANIMAL_OUTS
    ON ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
WHERE ANIMAL_INS.SEX_UPON_INTAKE LIKE 'Intact%' AND (ANIMAL_OUTS.SEX_UPON_OUTCOME LIKE 'Spayed%' OR ANIMAL_OUTS.SEX_UPON_OUTCOME LIKE 'Neutered%')
ORDER BY ANIMAL_OUTS.ANIMAL_ID;















select a.animal_id, a.animal_type, a.name
from animal_ins a
join animal_outs b
    on a.animal_id = b.animal_id
where
    a.sex_upon_intake like 'Intact%'
    and
    (
        b.sex_upon_outcome like 'Spayed%'
        or
        b.sex_upon_outcome like 'Neutered%'
    )
order by a.animal_id
;