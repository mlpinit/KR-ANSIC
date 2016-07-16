require "minitest/autorun"

class EntabTest < Minitest::Test

  def test_starting_position_and_nth_column
    input_file = "entab_test/four_tabs.txt"
    output_file = "entab_test/four_tabs.result"
    system(".././entab -3 +4 < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("entab_test/four_tabs.expected_result")
    assert_equal output_text, expected_output_text
  end

end
